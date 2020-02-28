#include "Console.h"

Console* Console::console;

Console::Console()
{
	
}

Console* Console::Get()
{
	if (console == nullptr)
	{
		console = new Console();
	}
	else
	{
		return console;
	}
}

void Console::PrintRaw(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "MESSAGE: " << message << "\n";
}

void Console::PrintInfo(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 9);
	cout << "MESSAGE: " << message << "\n";
}

void Console::PrintError(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	cout << "ERROR: " << message << "\n";
}

void Console::PrintWarning(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "ERROR: " << message << "\n";
}

void Console::PrintFatal(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "ERROR: " << message << "\n";
}