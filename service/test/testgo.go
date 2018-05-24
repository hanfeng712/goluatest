package test

/*
#cgo CFLAGS: -I/home/hanfeng/golang/src/golua/service/test
#cgo LDFLAGS: -L/home/hanfeng/golang/src/golua/service/test/ -llua5.2
#include "testc.h"
#include <stdlib.h>
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type GoluaOp struct {
	luaCtx unsafe.Pointer
}

var goluaHandler *GoluaOp

func (op *GoluaOp) Init() {
	op.luaCtx = C.init_lua()
	luaPath := "/home/hanfeng/golang/src/goluatest/testLua/HelloWord.lua"
	cluaPath := C.CString(luaPath)
	C.load_lua_file(op.luaCtx, cluaPath)
	C.free(unsafe.Pointer(cluaPath))
}

func Init() {
	goluaHandler = &GoluaOp{}
	goluaHandler.Init()
}
func AddTestFunc() {
	fmt.Print("start\n")
	fmt.Printf("1:go call C == AddTestFunc\n")
	C.cAddFuncLua(goluaHandler.luaCtx, 1)
}

//export AddCallFuncGo
func AddCallFuncGo(a int) int {
	fmt.Printf("3:C call go == AddCallFuncGo == a : %d\n", a)
	return a + 1
}

//export GetGoSecondTime
func GetGoSecondTime() int64 {
	return 1
}

//export GetGoMsecTime
func GetGoMsecTime() int64 {
	return 1
}

//export GetGoNsecTime
func GetGoNsecTime() int64 {
	return 1
}

//export GetConfigIntValueByKey
func GetConfigIntValueByKey() int {
	return 1
}
