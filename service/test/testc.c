#include "_obj/_cgo_export.h"
#include "testc.h"
#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <string.h>

extern int cAddFuncGo(lua_State *L);
extern int HttpRequestGet(lua_State *L);
extern int HttpRequestPost(lua_State *L);
extern int SendNoResponse(lua_State *L);

extern int luatime(lua_State *L);
extern int msectime(lua_State *L);
extern int nsectime(lua_State *L);
extern int addTimer(lua_State *L);
extern int addTimerMsec(lua_State *L);
extern int addClocker(lua_State *L);
extern int addCalender(lua_State *L);
extern int stacktrace(lua_State *L);
extern int GetConfigInt(lua_State *L);
extern int config(lua_State *L);
extern int Debug(lua_State *L);
extern int Info(lua_State *L);
extern int Warning(lua_State *L);
extern int Error(lua_State *L);
extern int BroadcastLuaProtoRawdata(lua_State *L);
extern int BroadcastString(lua_State *L);
extern int GetUUid62Hex(lua_State *L);
extern int RandBytes(lua_State *L);
extern int RandString(lua_State *L);
extern int RandString2(lua_State *L);
extern int ConvertChineseToSpell(lua_State *L);
extern int ConvertToTraditionalChinese(lua_State *L);
extern int VerifyRsa(lua_State *L);
extern int HttpCryptoEncode(lua_State *L);
extern int getserverlist(lua_State *L);
extern int dogmfunc(lua_State *L);




void *init_lua(){
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_newtable(L);
		//httpclient 对象
		lua_pushstring(L,"httpclient");
		lua_newtable(L);  
			lua_pushcfunction(L, HttpRequestGet);
    			lua_setfield(L, -2, "HttpRequestGet");
			lua_pushcfunction(L, HttpRequestPost);
    			lua_setfield(L, -2, "HttpRequestPost");
			lua_pushcfunction(L, SendNoResponse);
    			lua_setfield(L, -2, "SendNoResponse");
		lua_settable(L, 1);
		//时间戳
		lua_pushcfunction(L, luatime);
		lua_setfield(L, -2, "luatime");
		lua_pushstring(L,"systime");
		lua_newtable(L); 
			lua_pushcfunction(L, msectime);
    			lua_setfield(L, -2, "Msec");
			lua_pushcfunction(L, nsectime);
    			lua_setfield(L, -2, "Nsec");
		lua_settable(L, 1);
		//游戏区
		lua_pushstring(L,"gamezone");
		lua_newtable(L);
			lua_pushstring(L,GetGameZoneId());
			lua_setfield(L, -2, "Gameid");
		lua_settable(L, 1);
		//时区
		lua_pushstring(L,"timezone");
		lua_newtable(L);
			lua_pushstring(L,1);//TODO:hanfeng
			lua_setfield(L, -2, "Offset");
		lua_settable(L, 1);
		//logger
		lua_pushstring(L,"logging");
		lua_newtable(L);
			lua_pushcfunction(L, Debug);
    			lua_setfield(L, -2, "Debug");
			lua_pushcfunction(L, Info);
    			lua_setfield(L, -2, "Info");
			lua_pushcfunction(L, Warning);
    			lua_setfield(L, -2, "Warning");
			lua_pushcfunction(L, Error);
    			lua_setfield(L, -2, "Error");
		lua_settable(L, 1);
		//accountmgr
		lua_pushstring(L,"accountmgr");
		lua_newtable(L);
			lua_pushcfunction(L, BroadcastLuaProtoRawdata);
    			lua_setfield(L, -2, "BroadcastLuaProtoRawdata");
			lua_pushcfunction(L, BroadcastString);
    			lua_setfield(L, -2, "BroadcastString");
		lua_settable(L, 1);
		//rand
		lua_pushstring(L,"rand");
		lua_newtable(L);
			lua_pushcfunction(L, GetUUid);
    			lua_setfield(L, -2, "GetUUid");
			lua_pushcfunction(L, GetUUid62Hex);
    			lua_setfield(L, -2, "GetUUid62Hex");
			lua_pushcfunction(L, RandBytes);
    			lua_setfield(L, -2, "RandBytes");
			lua_pushcfunction(L, RandString);
    			lua_setfield(L, -2, "RandString");
			lua_pushcfunction(L, RandString2);
    			lua_setfield(L, -2, "RandString2");
			lua_pushcfunction(L, ConvertChineseToSpell);
    			lua_setfield(L, -2, "ConvertChineseToSpell");
			lua_pushcfunction(L, ConvertToTraditionalChinese);
    			lua_setfield(L, -2, "ConvertToTraditionalChinese");
		lua_settable(L, 1);
		//crypto
		lua_pushstring(L,"crypto");
		lua_newtable(L);
			lua_pushcfunction(L, VerifyRsa);
    			lua_setfield(L, -2, "VerifyRsa");
			lua_pushcfunction(L, HttpCryptoEncode);
    			lua_setfield(L, -2, "HttpCryptoEncode");
		lua_settable(L, 1);
		
		lua_pushcfunction(L, addTimer);
    		lua_setfield(L, -2, "addTimer");
		lua_pushcfunction(L, addTimerMsec);
    		lua_setfield(L, -2, "addTimerMsec");		
		lua_pushcfunction(L, addClocker);
    		lua_setfield(L, -2, "addClocker");
		lua_pushcfunction(L, addCalender);
    		lua_setfield(L, -2, "addCalender");
		lua_pushcfunction(L, stacktrace);
    		lua_setfield(L, -2, "stacktrace");
		lua_pushcfunction(L, getserverlist);
    		lua_setfield(L, -2, "getserverlist");
		lua_pushcfunction(L, dogmfunc);
    		lua_setfield(L, -2, "dogmfunc");
		//测试函数
		lua_pushcfunction(L, cAddFuncGo);
    		lua_setfield(L, -2, "cAddFuncGo");
    lua_setglobal(L, "go");
    return L;
}

int load_lua_file(void *p_luaCtx, const char *p_pszFilename){
    lua_State *L = (lua_State*)p_luaCtx;
    if( luaL_loadfile(L, p_pszFilename) ||
        lua_pcall(L, 0, 0, 0) ){
        return -1;
    }
    return 0;
}
void uninit(void *p_luaCtx){
    lua_State *L = (lua_State*)p_luaCtx;
    lua_close(L);
}
/***********************C调用lua************************************************/
//test
int cAddFuncLua(void *p_luaCtx,int param)
{
	lua_State *L = (lua_State*)p_luaCtx;
	lua_getglobal(L, "addFuncLua");
	lua_pushnumber(L, param);
	if( lua_pcall(L, 1, 0, 0) ){
        return -1;
    }
}
/***********************C调用go************************************************/
//test-lua-C多参数调用
int cAddFuncGo(lua_State *L)
{
	int param_count = lua_gettop(L);
    if ( param_count != 3 ){
        return luaL_error(L, "invalid parameter count!");
    }

    int threeParam = lua_tonumber(L, -1);
    lua_pop(L, 1);
    int result = AddCallFuncGo(threeParam);

	int TwoParam = lua_tonumber(L, -1);
    lua_pop(L, 1);
    result = AddCallFuncGo(TwoParam);
	
	int oneParam = lua_tonumber(L, -1);
    lua_pop(L, 1);
    result = AddCallFuncGo(oneParam);
	
    lua_pushnumber(L, result);
    return 1;
}

int luatime(lua_State *L)
{
	long long time = GetGoSecondTime();
	lua_pushnumber(L, time);
    return 1;
}

int msectime(lua_State *L)
{
	long long time = GetGoMsecTime();
	lua_pushnumber(L, time);
    return 1;
}
int nsectime(lua_State *L)
{
	long long time = GetGoNsecTime();
	lua_pushnumber(L, time);
    return 1;
}

int addTimer(lua_State *L)
{
	return 1;
}

int addTimerMsec(lua_State *L)
{
	return 1;
}

int addClocker(lua_State *L)
{
	return 1;
}
int addCalender(lua_State *L)
{
	return 1;
}
int stacktrace(lua_State *L)
{
	return 1;
}
int getserverlist(lua_State *L)
{
	return 1;
}
int dogmfunc(lua_State *L)
{
	return 1;
}
/****************config***********************/
int config(lua_State *L)
{
	lua_newtable(L); 
		lua_pushstring(L,"GetConfigInt");
		lua_pushcfunction(L, GetConfigInt);
		lua_settable(L, -3);
	return 1;	
}

int GetConfigInt(lua_State *L)
{
	int param_count = lua_gettop(L);
	if ( param_count != 1 ){
        return luaL_error(L, "invalid parameter count!");
    }
	const char* keyParam = lua_tostring(L, -1);
    lua_pop(L, 1);
	GoString keyValue;
	keyValue.p = keyParam;
	keyValue.n = strlen(keyParam);
	int result = GetConfigIntValueByKey(keyValue);
	lua_pushnumber(L, result);
	return 1;
}

/****************logger******************************/
int Debug(lua_State *L)
{
	return 1;
}
int Info(lua_State *L)
{
	return 1;
}
int Warning(lua_State *L)
{
	return 1;
}

int Error(lua_State *L)
{
	return 1;
}

/****************accountmgr****************************/
int BroadcastLuaProtoRawdata(lua_State *L)
{
	return 1;
}
int BroadcastString(lua_State *L)
{
	return 1;
}

/****************Rand****************************/
int GetUUid62Hex(lua_State *L);
{
	return 1;
}
int RandBytes(lua_State *L)
{
	return 1;
}
int RandString(lua_State *L)
{
	return 1;
}
int RandString2(lua_State *L)
{
	return 1;
}
int ConvertChineseToSpell(lua_State *L)
{
	return 1;
}
int ConvertToTraditionalChinese(lua_State *L)
{
	return 1;
}
/****************crypto*****************************/
int VerifyRsa(lua_State *L)
{
	return 1;
}
int HttpCryptoEncode(lua_State *L)
{
	return 1;
}
/****************httpclient*******************/
//1:id 2:http的Get参数-string,3:结果回调函数-string,4:url地址-string,5:url请求头-table
int HttpRequestGet(lua_State *L)
{
	int param_count = lua_gettop(L);
    
	const char urlHead[10][128];
	lua_pushstring(L, "Content-Type");
	lua_gettable(L, 1); 
	const char* context = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Origin");
	lua_gettable(L, 1); 
	const char* origin = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Host");
	lua_gettable(L, 1); 
	const char* host = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Referer");
	lua_gettable(L, 1); 
	const char* referer = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "User-Agent");
	lua_gettable(L, 1); 
	const char* userAgent = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "X-Requested-With");
	lua_gettable(L, 1); 
	const char* requested = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Accept");
	lua_gettable(L, 1); 
	const char* accept = lua_tostring(L, -1);
	lua_pop(L, 1);
		
	const char* urlIp = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* luaCallFunc = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* urlParam = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	int id = lua_tonumber(L, -1);
	lua_pop(L, 1);
	
	//TODO:go实现http的Get代码
	return 1;
}

//1:id 2:http的Post参数-string,3:http请求回调函数-string,4:url地址-string,5:url请求类型-string,6:Post参数-string,7:url请求头-table
int HttpRequestPost(lua_State *L)
{
	int param_count = lua_gettop(L);
    
	lua_pushstring(L, "Content-Type");
	lua_gettable(L, 1); 
	const char* context = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Origin");
	lua_gettable(L, 1); 
	const char* origin = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Host");
	lua_gettable(L, 1); 
	const char* host = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Referer");
	lua_gettable(L, 1); 
	const char* referer = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "User-Agent");
	lua_gettable(L, 1); 
	const char* userAgent = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "X-Requested-With");
	lua_gettable(L, 1); 
	const char* requested = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	lua_pushstring(L, "Accept");
	lua_gettable(L, 1); 
	const char* accept = lua_tostring(L, -1);
	lua_pop(L, 1);
		
	const char* reqMsg = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* bodyType = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* url = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* resFunc = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	const char* callbackpara = lua_tostring(L, -1);
	lua_pop(L, 1);
	
	int id = lua_tonumber(L, -1);
	lua_pop(L, 1);//
	
	//TODO:go实现http的Post代码
	return 1;
}

int SendNoResponse(lua_State *L)
{
	return 1;
}

