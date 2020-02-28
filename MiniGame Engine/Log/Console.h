#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
enum class type
{
	Default,
	Warning,
	Error,
	Fatal,
};

class Console
{
public:
	static Console* Get();
private:
	Console();
	~Console();
	static Console* console;
public:
	void PrintRaw(string message);
	void PrintError(string message);
	void PrintWarning(string message);
	void PrintFatal(string message);
	void PrintInfo(string message);
};