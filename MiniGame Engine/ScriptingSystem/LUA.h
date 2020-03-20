#pragma once
extern "C" {
#include "../../ExternalLibs/LUA/include/lua.h" 
#include "../../ExternalLibs/LUA/include/lauxlib.h" 
#include "../../ExternalLibs/LUA/include/lualib.h" 
}
#ifdef _WIN32
#pragma comment(lib, "../../ExternalLibs/LUA/liblua53.a")
#endif // _WIN32

#include <string>
#include "../GOM/Sprite.h"

using std::string;


class LUA
{
public:
	static LUA* GetPTR();
	lua_State* GetState();
	void Test(string fileName);
	void TestCallFunctionFromCPP(string fileName);
	void Lua_MoveObject(string fileName);
	void Lua_CreatePrimitve(string fileName);
	bool CheckLua(lua_State* l, int r);
private:
	static LUA* ptr;
	LUA();
	~LUA();
	lua_State* _state;
};