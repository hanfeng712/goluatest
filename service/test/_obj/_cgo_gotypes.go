// Created by cgo - DO NOT EDIT

package test

import "unsafe"

import _ "runtime/cgo"

import "syscall"

var _ syscall.Errno
func _Cgo_ptr(ptr unsafe.Pointer) unsafe.Pointer { return ptr }

//go:linkname _Cgo_always_false runtime.cgoAlwaysFalse
var _Cgo_always_false bool
//go:linkname _Cgo_use runtime.cgoUse
func _Cgo_use(interface{})
type _Ctype_char int8

type _Ctype_int int32

type _Ctype_void [0]byte

//go:linkname _cgo_runtime_cgocall runtime.cgocall
func _cgo_runtime_cgocall(unsafe.Pointer, uintptr) int32

//go:linkname _cgo_runtime_cgocallback runtime.cgocallback
func _cgo_runtime_cgocallback(unsafe.Pointer, unsafe.Pointer, uintptr, uintptr)

//go:linkname _cgoCheckPointer runtime.cgoCheckPointer
func _cgoCheckPointer(interface{}, ...interface{})

//go:linkname _cgoCheckResult runtime.cgoCheckResult
func _cgoCheckResult(interface{})


func _Cfunc_CString(s string) *_Ctype_char {
	p := _cgo_cmalloc(uint64(len(s)+1))
	pp := (*[1<<30]byte)(p)
	copy(pp[:], s)
	pp[len(s)] = 0
	return (*_Ctype_char)(p)
}
//go:cgo_import_static _cgo_673ca8978595_Cfunc_cAddFuncLua
//go:linkname __cgofn__cgo_673ca8978595_Cfunc_cAddFuncLua _cgo_673ca8978595_Cfunc_cAddFuncLua
var __cgofn__cgo_673ca8978595_Cfunc_cAddFuncLua byte
var _cgo_673ca8978595_Cfunc_cAddFuncLua = unsafe.Pointer(&__cgofn__cgo_673ca8978595_Cfunc_cAddFuncLua)

//go:cgo_unsafe_args
func _Cfunc_cAddFuncLua(p0 unsafe.Pointer, p1 _Ctype_int) (r1 _Ctype_int) {
	_cgo_runtime_cgocall(_cgo_673ca8978595_Cfunc_cAddFuncLua, uintptr(unsafe.Pointer(&p0)))
	if _Cgo_always_false {
		_Cgo_use(p0)
		_Cgo_use(p1)
	}
	return
}
//go:cgo_import_static _cgo_673ca8978595_Cfunc_free
//go:linkname __cgofn__cgo_673ca8978595_Cfunc_free _cgo_673ca8978595_Cfunc_free
var __cgofn__cgo_673ca8978595_Cfunc_free byte
var _cgo_673ca8978595_Cfunc_free = unsafe.Pointer(&__cgofn__cgo_673ca8978595_Cfunc_free)

//go:cgo_unsafe_args
func _Cfunc_free(p0 unsafe.Pointer) (r1 _Ctype_void) {
	_cgo_runtime_cgocall(_cgo_673ca8978595_Cfunc_free, uintptr(unsafe.Pointer(&p0)))
	if _Cgo_always_false {
		_Cgo_use(p0)
	}
	return
}
//go:cgo_import_static _cgo_673ca8978595_Cfunc_init_lua
//go:linkname __cgofn__cgo_673ca8978595_Cfunc_init_lua _cgo_673ca8978595_Cfunc_init_lua
var __cgofn__cgo_673ca8978595_Cfunc_init_lua byte
var _cgo_673ca8978595_Cfunc_init_lua = unsafe.Pointer(&__cgofn__cgo_673ca8978595_Cfunc_init_lua)

//go:cgo_unsafe_args
func _Cfunc_init_lua() (r1 unsafe.Pointer) {
	_cgo_runtime_cgocall(_cgo_673ca8978595_Cfunc_init_lua, uintptr(unsafe.Pointer(&r1)))
	if _Cgo_always_false {
	}
	return
}
//go:cgo_import_static _cgo_673ca8978595_Cfunc_load_lua_file
//go:linkname __cgofn__cgo_673ca8978595_Cfunc_load_lua_file _cgo_673ca8978595_Cfunc_load_lua_file
var __cgofn__cgo_673ca8978595_Cfunc_load_lua_file byte
var _cgo_673ca8978595_Cfunc_load_lua_file = unsafe.Pointer(&__cgofn__cgo_673ca8978595_Cfunc_load_lua_file)

//go:cgo_unsafe_args
func _Cfunc_load_lua_file(p0 unsafe.Pointer, p1 *_Ctype_char) (r1 _Ctype_int) {
	_cgo_runtime_cgocall(_cgo_673ca8978595_Cfunc_load_lua_file, uintptr(unsafe.Pointer(&p0)))
	if _Cgo_always_false {
		_Cgo_use(p0)
		_Cgo_use(p1)
	}
	return
}
//go:cgo_export_dynamic AddCallFuncGo
//go:linkname _cgoexp_673ca8978595_AddCallFuncGo _cgoexp_673ca8978595_AddCallFuncGo
//go:cgo_export_static _cgoexp_673ca8978595_AddCallFuncGo
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_AddCallFuncGo(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_AddCallFuncGo
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_AddCallFuncGo(p0 int) (r0 int) {
	return AddCallFuncGo(p0)
}
//go:cgo_export_dynamic GetGoSecondTime
//go:linkname _cgoexp_673ca8978595_GetGoSecondTime _cgoexp_673ca8978595_GetGoSecondTime
//go:cgo_export_static _cgoexp_673ca8978595_GetGoSecondTime
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_GetGoSecondTime(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_GetGoSecondTime
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_GetGoSecondTime() (r0 int64) {
	return GetGoSecondTime()
}
//go:cgo_export_dynamic GetGoMsecTime
//go:linkname _cgoexp_673ca8978595_GetGoMsecTime _cgoexp_673ca8978595_GetGoMsecTime
//go:cgo_export_static _cgoexp_673ca8978595_GetGoMsecTime
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_GetGoMsecTime(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_GetGoMsecTime
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_GetGoMsecTime() (r0 int64) {
	return GetGoMsecTime()
}
//go:cgo_export_dynamic GetGoNsecTime
//go:linkname _cgoexp_673ca8978595_GetGoNsecTime _cgoexp_673ca8978595_GetGoNsecTime
//go:cgo_export_static _cgoexp_673ca8978595_GetGoNsecTime
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_GetGoNsecTime(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_GetGoNsecTime
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_GetGoNsecTime() (r0 int64) {
	return GetGoNsecTime()
}
//go:cgo_export_dynamic GetConfigIntValueByKey
//go:linkname _cgoexp_673ca8978595_GetConfigIntValueByKey _cgoexp_673ca8978595_GetConfigIntValueByKey
//go:cgo_export_static _cgoexp_673ca8978595_GetConfigIntValueByKey
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_GetConfigIntValueByKey(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_GetConfigIntValueByKey
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_GetConfigIntValueByKey(p0 string) (r0 int) {
	return GetConfigIntValueByKey(p0)
}
//go:cgo_export_dynamic GetGameZoneId
//go:linkname _cgoexp_673ca8978595_GetGameZoneId _cgoexp_673ca8978595_GetGameZoneId
//go:cgo_export_static _cgoexp_673ca8978595_GetGameZoneId
//go:nosplit
//go:norace
func _cgoexp_673ca8978595_GetGameZoneId(a unsafe.Pointer, n int32, ctxt uintptr) {
	fn := _cgoexpwrap_673ca8978595_GetGameZoneId
	_cgo_runtime_cgocallback(**(**unsafe.Pointer)(unsafe.Pointer(&fn)), a, uintptr(n), ctxt);
}

func _cgoexpwrap_673ca8978595_GetGameZoneId() (r0 int) {
	return GetGameZoneId()
}

//go:cgo_import_static _cgo_673ca8978595_Cfunc__Cmalloc
//go:linkname __cgofn__cgo_673ca8978595_Cfunc__Cmalloc _cgo_673ca8978595_Cfunc__Cmalloc
var __cgofn__cgo_673ca8978595_Cfunc__Cmalloc byte
var _cgo_673ca8978595_Cfunc__Cmalloc = unsafe.Pointer(&__cgofn__cgo_673ca8978595_Cfunc__Cmalloc)

//go:linkname runtime_throw runtime.throw
func runtime_throw(string)

//go:cgo_unsafe_args
func _cgo_cmalloc(p0 uint64) (r1 unsafe.Pointer) {
	_cgo_runtime_cgocall(_cgo_673ca8978595_Cfunc__Cmalloc, uintptr(unsafe.Pointer(&p0)))
	if r1 == nil {
		runtime_throw("runtime: C malloc failed")
	}
	return
}
