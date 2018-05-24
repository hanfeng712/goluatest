#include "_obj/_cgo_export.h"
#include "testc.h"
#include <stdlib.h>
#include <error.h>
#include <stdio.h>

extern int cAddFuncGo(lua_State *L);
extern int HttpRequestGet(lua_State *L);
extern int HttpRequestPost(lua_State *L);

extern int luatime(lua_State *L);
extern int msectime(lua_State *L);
extern int nsectime(lua_State *L);

extern int GetConfigInt(lua_State *L);
extern int config(lua_State *L);

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
		//config
		lua_pushstring(L,"goconfig");
		lua_newtable(L); 
			lua_pushcfunction(L, GetConfigInt);
    			lua_setfield(L, -2, "GetConfigInt");
		lua_settable(L, 1);
		lua_pushcfunction(L, config);
		lua_setfield(L, -2, "config");
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

/****************config***********************/
int GetConfigInt(lua_State *L)
{
	int param_count = lua_gettop(L);
	if ( param_count != 1 ){
        return luaL_error(L, "invalid parameter count!");
    }
	const char* keyParam = lua_tostring(L, -1);
    lua_pop(L, 1);
	int result = GetConfigIntValueByKey();
	lua_pushnumber(L, result);
	return 1;
}

int config(lua_State *L)
{
	lua_pushstring(L, "goconfig");
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

