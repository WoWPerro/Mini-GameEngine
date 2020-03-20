#pragma once
extern "C" {
#include "../../ExternalLibs/LUA/include/lua.h" 
#include "../../ExternalLibs/LUA/include/lauxlib.h" 
#include "../../ExternalLibs/LUA/include/lualib.h" 
}
#ifdef _WIN32
#pragma comment(lib, "../../ExternalLibs/LUA/liblua53.a")
#endif // _WIN32