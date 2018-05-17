package cmd

import (
	"golua/service/dlog"
	"net/http"
	"runtime/debug"
	"syscall"
)

type CmdHandler interface {
	ServeHTTP(http.ResponseWriter, *http.Request)
	Init(config interface{}) error
	ConfigStruct() interface{}
	Uninit()
}

var CmdServerMux = http.NewServeMux()
var CmdHandlers map[string]CmdHandler

func init() {
	CmdHandlers = make(map[string]CmdHandler)
}

func RegisterCmd(name string, dir bool, handler CmdHandler) {
	CmdHandlers[name] = handler
	pattern := ""
	if dir == true {
		pattern = "/" + name + "/"
	} else {
		pattern = "/" + name
	}

	CmdServerMux.Handle(pattern, SafeHandler(handler))
}

func Uninit() {
	for _, handler := range CmdHandlers {
		handler.Uninit()
	}
}

func SafeHandler(handler http.Handler) http.HandlerFunc {
	return func(w http.ResponseWriter, req *http.Request) {
		dlog.Printf("%(+v)\n", req)
		defer func() {
			if err, ok := recover().(error); ok {
				http.Error(w, err.Error(), http.StatusInternalServerError)
				dlog.EPrintln("WARN: panic in %v - %v", handler, err)
				dlog.EPrintln(string(debug.Stack()))
			}
		}()
		handler.ServeHTTP(w, req)
	}
}

type DiskStatus struct {
	All  uint64 `json:"all"`
	Used uint64 `json:"used"`
	Free uint64 `json:"free"`
}

// disk usage of path/disk
func DiskUsage(path string) (disk DiskStatus) {
	fs := syscall.Statfs_t{}
	err := syscall.Statfs(path, &fs)
	if err != nil {
		return
	}
	disk.All = fs.Blocks * uint64(fs.Bsize)
	disk.Free = fs.Bfree * uint64(fs.Bsize)
	disk.Used = disk.All - disk.Free
	return
}
