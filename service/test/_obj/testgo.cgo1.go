// Created by cgo - DO NOT EDIT

//line /home/hanfeng/golang/src/golua/service/test/testgo.go:1
package test

//line /home/hanfeng/golang/src/golua/service/test/testgo.go:1
import _cgo_unsafe "unsafe"

//line /home/hanfeng/golang/src/golua/service/test/testgo.go:10
import (
	"fmt"
	"unsafe"
)

type GoluaOp struct {
	luaCtx unsafe.Pointer
}

var goluaHandler *GoluaOp

func (op *GoluaOp) Init() {
									op.luaCtx = _Cfunc_init_lua()
									luaPath := "/home/hanfeng/golang/src/golua/testLua/HelloWord.lua"
									cluaPath := _Cfunc_CString(luaPath)
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:24
	func(_cgo0 _cgo_unsafe.Pointer, _cgo1 *_Ctype_char) _Ctype_int {
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:24
		_cgoCheckPointer(_cgo0)
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:24
		return _Cfunc_load_lua_file(_cgo0, _cgo1)
									}(op.luaCtx, cluaPath)
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:25
	func(_cgo0 _cgo_unsafe.Pointer) {
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:25
		_cgoCheckPointer(_cgo0)
										_Cfunc_free(_cgo0)
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:26
	}(unsafe.Pointer(cluaPath))
}

func Init() {
	goluaHandler = &GoluaOp{}
	goluaHandler.Init()
}
func AddTestFunc() {
	fmt.Print("start\n")
	var i int = 1
	for ; i < 100000000; i++ {
										fmt.Printf("1:go call C == AddTestFunc\n")
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:37
		func(_cgo0 _cgo_unsafe.Pointer, _cgo1 _Ctype_int) _Ctype_int {
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:37
			_cgoCheckPointer(_cgo0)
//line /home/hanfeng/golang/src/golua/service/test/testgo.go:37
			return _Cfunc_cAddFuncLua(_cgo0, _cgo1)
		}(goluaHandler.luaCtx, _Ctype_int(i))
	}

//line /home/hanfeng/golang/src/golua/service/test/testgo.go:42
}

//line /home/hanfeng/golang/src/golua/service/test/testgo.go:45
func AddCallFuncGo(a int) int {
	fmt.Printf("3:C call go == AddCallFuncGo\n")
	return a + 1
}
