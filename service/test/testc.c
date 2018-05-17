#include "_obj/_cgo_export.h"
#include "testc.h"
#include <stdlib.h>
#include <error.h>
#include <stdio.h>

extern int cAddFuncGo(lua_State *L);

void *init_lua(){
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_newtable(L);
		lua_pushstring(L,"httpclient");
		lua_newtable(L);  
    			lua_pushcfunction(L, cAddFuncGo);
    			lua_setfield(L, -2, "cAddFuncGo");
		lua_settable(L, 1);
		
		lua_pushstring(L,"test");
		lua_newtable(L);  
    			lua_pushcfunction(L, test);
    			lua_setfield(L, -2, "test");
		lua_settable(L, 1);
    lua_setglobal(L, "go");
    return L;
}

int test()
{
	return 1;
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
int cAddFuncGo(lua_State *L)
{
	int param_count = lua_gettop(L);
    if ( param_count != 1 ){
        return luaL_error(L, "invalid parameter count!");
    }
    int reqCtx = lua_tonumber(L, -1);
    lua_pop(L, 1);
    int result = AddCallFuncGo(reqCtx);
    lua_pushnumber(L, result);
    return 1;
}

