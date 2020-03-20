#include "LUA.h"
#include <iostream>

LUA* LUA::ptr = nullptr;


LUA::LUA()
{
	_state = luaL_newstate();
	luaL_openlibs(_state);
}

LUA::~LUA()
{
	lua_close(_state);
}

LUA* LUA::GetPTR()
{
	if (!ptr)
		ptr = new LUA();

	return ptr;
}

inline int lua_HostFunction(lua_State* lua)
{
	float a = (float)lua_tonumber(lua, 1);
	float b = (float)lua_tonumber(lua, 2);
	//cout << "[C++] HostFunction(" << a << ")(" << b << ") has been called\n";
	float c = a * b;
	lua_pushnumber(lua, c);
	return 1;
}



lua_State* LUA::GetState()
{
	return _state;
}

void LUA::Test(string fileName)
{
	try
	{
		_state = luaL_newstate();
		luaL_openlibs(_state);
		if (CheckLua(_state, luaL_dofile(_state, fileName.c_str())))
		{
			auto lua_CreateObject = [](lua_State* lua) -> int
			{
				Sprite* image = (Sprite*)lua_newuserdata(lua, sizeof(Sprite*));
				return 1;
			};

			auto lua_MoveObject = [](lua_State* lua)-> int {
				int state = -3;
				Sprite* image = (Sprite*)lua_touserdata(lua, -4);
				//image->x = image->y = 0;
				lua_pop(lua, state); state++;
				lua_Number vecX = lua_tonumber(lua, state);
				lua_pop(lua, state); state++;
				lua_Number vecY = lua_tonumber(lua, state);
				lua_pop(lua, state); state++;
				image->SetX((int)vecX);
				image->SetY((int)vecY);
				return 0;
			};

			/*auto DestroyObject = [](lua_State* lua)-> int {
				return 0;
			}*/

			lua_register(_state, "CreateSprite", lua_CreateObject);
			lua_getglobal(_state, "CreateLuaSprite");
			lua_getglobal(_state, "sprite");

			//lua_register(_state, "CreateObject", image->LoadPath());

			if (lua_isfunction(_state, -1))
			{
				lua_pushfstring(_state, "path");
				if (CheckLua(_state, lua_pcall(_state, 1, 1, 0)))
				{
					std::cout << (string)lua_tostring(_state, -1) << std::endl;
				}

			}

		}
		else
		{
			throw(fileName);
		}
		lua_close(_state);
	}
	catch (string str)
	{
		//cout << "The file: " << str << " doesn't exist\n";
	}
	catch (...)
	{

	}
}

	void LUA::TestCallFunctionFromCPP(string fileName)
	{
		const char* c = fileName.c_str();

		lua_register(_state, "HostFunction", lua_HostFunction);
		if (CheckLua(_state, luaL_dofile(_state, fileName.c_str())))
		{

			lua_getglobal(_state, "DoAThing");
			if (lua_isfunction(_state, -1))
			{
				lua_pushnumber(_state, 3.4f);
				lua_pushnumber(_state, 9.1f);
				if (CheckLua(_state, lua_pcall(_state, 2, 1, 0)))
				{
					std::cout << (float)lua_tonumber(_state, -1) << std::endl;
				}
			}

		}
		lua_close(_state);
	}

	void LUA::Lua_MoveObject(string fileName)
	{
		try
		{
			if (CheckLua(_state, luaL_dofile(_state, fileName.c_str())))
			{
				if (lua_isfunction(_state, -1))
				{

				}
			}
		}
		catch (...)
		{

		}
	}

	void LUA::Lua_CreatePrimitve(string fileName)
	{
	}


	bool LUA::CheckLua(lua_State * l, int r)
	{
		try
		{

			if (r != LUA_OK)
			{
				throw(false);
			}
			return true;
		}
		catch (bool b)
		{
			string errorMSG = lua_tostring(l, -1);
			std::cout << errorMSG << std::endl;
		}
		return false;
	}