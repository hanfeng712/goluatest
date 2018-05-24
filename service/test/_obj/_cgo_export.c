/* Created by cgo - DO NOT EDIT. */
#include <stdlib.h>
#include "_cgo_export.h"

extern void crosscall2(void (*fn)(void *, int, __SIZE_TYPE__), void *, int, __SIZE_TYPE__);
extern __SIZE_TYPE__ _cgo_wait_runtime_init_done();
extern void _cgo_release_context(__SIZE_TYPE__);

extern char* _cgo_topofstack(void);
#define CGO_NO_SANITIZE_THREAD
#define _cgo_tsan_acquire()
#define _cgo_tsan_release()

extern void _cgoexp_7fc2fcb0c328_AddCallFuncGo(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt AddCallFuncGo(GoInt p0)
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoInt p0;
		GoInt r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	a.p0 = p0;
	_cgo_tsan_release();
	crosscall2(_cgoexp_7fc2fcb0c328_AddCallFuncGo, &a, 16, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}
extern void _cgoexp_7fc2fcb0c328_GetGoSecondTime(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt64 GetGoSecondTime()
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoInt64 r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	_cgo_tsan_release();
	crosscall2(_cgoexp_7fc2fcb0c328_GetGoSecondTime, &a, 8, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}
extern void _cgoexp_7fc2fcb0c328_GetGoMsecTime(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt64 GetGoMsecTime()
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoInt64 r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	_cgo_tsan_release();
	crosscall2(_cgoexp_7fc2fcb0c328_GetGoMsecTime, &a, 8, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}
extern void _cgoexp_7fc2fcb0c328_GetGoNsecTime(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt64 GetGoNsecTime()
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoInt64 r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	_cgo_tsan_release();
	crosscall2(_cgoexp_7fc2fcb0c328_GetGoNsecTime, &a, 8, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}
extern void _cgoexp_7fc2fcb0c328_GetConfigIntValueByKey(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt GetConfigIntValueByKey()
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoInt r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	_cgo_tsan_release();
	crosscall2(_cgoexp_7fc2fcb0c328_GetConfigIntValueByKey, &a, 8, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}

CGO_NO_SANITIZE_THREAD
void _cgo_7fc2fcb0c328_Cfunc__Cmalloc(void *v) {
	struct {
		unsigned long long p0;
		void *r1;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	void *ret;
	_cgo_tsan_acquire();
	ret = malloc(a->p0);
	if (ret == 0 && a->p0 == 0) {
		ret = malloc(1);
	}
	a->r1 = ret;
	_cgo_tsan_release();
}
