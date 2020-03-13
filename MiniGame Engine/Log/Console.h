#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <string>
#include <iostream>
#include "../DataBase/ListaT.h"
#include <chrono>
#include <ctime>
#include <fstream>

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
	int VerboLevel = 1;
	time_t timer = time(NULL);
	struct tm newLocal;
	std::ofstream historial;
	Console();
	~Console();
	static Console* console;
	ListaT<string> Spanish;
	ListaT<string> English;
	ListaT<string> ESP_INFO;
	ListaT<string> ESP_WARN;
	ListaT<string> ESP_ERR;
	ListaT<string> ESP_FATL;
	ListaT<string> ENG_INFO;
	ListaT<string> ENG_WARN;
	ListaT<string> ENG_ERR;
	ListaT<string> ENG_FATL;
	void SetStrings();
	void SetCodes();
	string GetDate();
	bool ESP = false;
	bool ENG = true;
	bool config;
public:
	int GetVerbo();
	void SetVerbo(string v);
	void SetIdiom(string i);
	void PrintRaw(string message);
	void PrintError(string message);
	void PrintError(int code);
	void PrintWarning(string message);
	void PrintWarning(int code);
	void PrintFatal(string message);
	void PrintFatal(int code);
	void PrintInfo(string message);
	void PrintInfo(int code);
};