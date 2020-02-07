#include "Console.h"

Console* Console::console;

Console::Console()
{
	console = console->Get();
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