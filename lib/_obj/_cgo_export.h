/* Created by cgo - DO NOT EDIT. */



typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef __complex float GoComplex64;
typedef __complex double GoComplex128;

typedef struct { char *p; GoInt n; } GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;


extern char* GetURIPath(void* p0);

/* Return type for ReadBodyData */
struct ReadBodyData_return {
	char* r0;
	GoInt r1;
};

extern struct ReadBodyData_return ReadBodyData(void* p0);

extern int WriteData(void* p0, char* p1, GoInt p2);
