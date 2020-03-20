#pragma once
#include "LUA.h"
#include "lua.h"
#include <string>
#include "../Log/Console.h"
#include <vector>
//https://eliasdaler.wordpress.com/2013/10/11/lua_cpp_binder/

using std::string;

class LuaScript
{
public:
private:
	lua_State* L;
	int level;

public:
	LuaScript(const std::string& filename);
	void printError(const std::string& variableName, const std::string& reason);
	template<typename T> T get(const std::string& variableName)
	{
		if (!L)
		{
			printError(variableName, "Script is not loaded");
			return lua_getdefault<T>();
		}

		T result;
		if (lua_gettostack(variableName))
		{ // variable succesfully on top of stack
			result = lua_get<T>(variableName);
		}
		else
		{
			result = lua_getdefault<T>();
		}

		lua_pop(L, level + 1); // pop all existing elements from stack
		return result;
	}
	bool lua_gettostack(const std::string& variableName)
	{
		level = 0;
		std::string var = "";
		for (unsigned int i = 0; i < variableName.size(); i++)
		{
			if (variableName.at(i) == '.')
			{
				if (level == 0)
				{
					lua_getglobal(L, var.c_str());
				}
				else
				{
					lua_getfield(L, -1, var.c_str());
				}

				if (lua_isnil(L, -1))
				{
					printError(variableName, var + " is not defined");
					return false;
				}
				else
				{
					var = "";
					level++;
				}
			}
			else
			{
				var += variableName.at(i);
			}
		}
		if (level == 0)
		{
			lua_getglobal(L, var.c_str());
		}
		else
		{
			lua_getfield(L, -1, var.c_str());
		}
		if (lua_isnil(L, -1))
		{
			printError(variableName, var + " is not defined");
			return false;
		}

		return true;
	}

	// Generic get
	template <typename T> T lua_get(const std::string& variableName)
	{
		return 0;
	}

	// Generic default get
	template <typename T> T lua_getdefault(const std::string& variableName)
	{
		return 0;
	}

	template<typename T> inline std::string LuaScript::lua_getdefault()
	{
		return "null";
	}
	template <typename T> inline bool LuaScript::lua_get(const std::string& variableName)
	{
		return (bool)lua_toboolean(L, -1);
	}

	template <typename T> inline float LuaScript::lua_get(const std::string& variableName)
	{
		if (!lua_isnumber(L, -1))
		{
			printError(variableName, "Not a number");
		}
		return (float)lua_tonumber(L, -1);
	}

	template <typename T> inline int LuaScript::lua_get(const std::string& variableName)
	{
		if (!lua_isnumber(L, -1))
		{
			printError(variableName, "Not a number");
		}
		return (int)lua_tonumber(L, -1);
	}

	template <typename T> inline std::string LuaScript::lua_get(const std::string& variableName)
	{
		std::string s = "null";
		if (lua_isstring(L, -1))
		{
			s = std::string(lua_tostring(L, -1));
		}
		else
		{
			printError(variableName, "Not a string");
		}
		return s;
	}
	~LuaScript();
};