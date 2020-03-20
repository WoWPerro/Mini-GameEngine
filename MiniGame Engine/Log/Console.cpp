#include "Console.h"
#include <fstream>

using std::ifstream;
Console* Console::console;

Console::Console()
{
	SetStrings();
}

Console* Console::Get()
{
	if (console == nullptr)
	{
		console = new Console();
		return console;
	}
	else
	{
		return console;
	}
}

void Console::SaveConsole()
{
	std::ofstream outfile("C:\\Dev_WoWperro\\source\\repos\\7_Trimestre\\Diseño de Sistemas de juegos\\MiniGame Engine\\Debug\\EngineConfig\\Console.txt");
	outfile << FINALMESSAGE;
	outfile.close();
}

int Console::GetVerbo()
{
	return VerboLevel;
}

void Console::SetVerbo(string v)
{
	VerboLevel = std::stoi(v);
}

void Console::SetIdiom(string i)
{
	if (i == "ESPANOL")
	{
		ESP = true;
		ENG = false;
	}
	else if (i == "ENGLISH")
	{
		ENG = true;
		ESP = false;
	}
}

void Console::PrintRaw(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	string date = GetDate();
	cout << "[" << date << "]" << "MESSAGE: " << message << "\n";
	FINALMESSAGE += "[" + date + "]" + "MESSAGE: " + message + "\n";
	/*historial.open();
	historial << "[" << date << "]" << "MESSAGE: " << message << "\n";
	historial.close();*/
}

void Console::PrintInfo(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 9);
	string date = GetDate();
	cout << "[" << date << "]" << "INFO: " << message << "\n";
	FINALMESSAGE += "[" + date + "]" + "INFO: " + message + "\n";
}

void Console::PrintError(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	string date = GetDate();
	cout << "[" << date << "]" << "ERROR: " << message << "\n";
	FINALMESSAGE += "[" + date + "]" + "ERROR: " + message + "\n";
}

void Console::PrintWarning(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	string date = GetDate();
	cout << "[" << date << "]" << "WARNING: " << message << "\n";
	FINALMESSAGE += "[" + date + "]" + "WARNING: " + message + "\n";
}

void Console::PrintFatal(string message)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	string date = GetDate();
	cout << "[" << date << "]" << "FATAL: " << message << "\n";
	FINALMESSAGE += "[" + date + "]" + "FATAL: " + message + "\n";
}

void Console::PrintInfo(int code)
{
	code =  code - 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 9); 
	string date = GetDate();
	if (ESP)
	{
		cout << "[" << date << "]" << "INFO: " << ESP_INFO.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "INFO: " + ESP_INFO.get_at(code)->value + "\n";
	}
	else if (ENG)
	{
		cout << "[" << date << "]" << "INFO: " << ENG_INFO.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "INFO: " + ENG_INFO.get_at(code)->value + "\n";
	}
}

void Console::PrintError(int code)
{
	code--;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	string date = GetDate();
	if (ESP)
	{
		cout << "[" << date << "]" << "ERROR: " << ESP_ERR.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "ERROR: " + ESP_ERR.get_at(code)->value + "\n";
	}
	else if (ENG)
	{
		cout << "[" << date << "]" << "ERROR: " << ENG_ERR.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "ERROR: " + ENG_ERR.get_at(code)->value + "\n";
	}
}

void Console::PrintWarning(int code)
{
	code--;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	string date = GetDate();
	if (ESP)
	{
		cout << "[" << date << "]" << "WARNING: " << ESP_WARN.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "WARNING: " + ESP_WARN.get_at(code)->value + "\n";
	}
	else if (ENG)
	{
		cout << "[" << date << "]" << "WARNING: " << ENG_WARN.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "WARNING: " + ENG_WARN.get_at(code)->value + "\n";
	}
}

void Console::PrintFatal(int code)
{
	newLocal = *localtime(&timer);
	code--;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	string date = GetDate();
	if (ESP)
	{
		cout << "[" << date << "]" << "FATAL: " << ESP_FATL.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "FATAL: " + ENG_FATL.get_at(code)->value + "\n";
	}
	else if (ENG)
	{
		cout << "[" << date << "]" << "FATAL: " << ENG_FATL.get_at(code)->value << "\n";
		FINALMESSAGE += "[" + date + "]" + "FATAL: " + ENG_FATL.get_at(code)->value + "\n";
	}
}

void Console::SetStrings()
{
	if (!config)
	{
		config = true;
		bool español = false;
		bool ingles = false;
		string line;
		ifstream localized;
		localized.open("C:\\Dev_WoWperro\\source\\repos\\7_Trimestre\\Diseño de Sistemas de juegos\\MiniGame Engine\\Debug\\EngineConfig\\Localized.txt");
		if (!localized)
		{
			cout << "ERR00\n";
			exit(1);
		}
		else
		{
			while (std::getline(localized, line))
			{
				if (line == "ESPANOL")
				{
					español = true;
					ingles = false;
				}
				else if (line == "INGLES")
				{
					español = false;
					ingles = true;
				}
				else
				{
					if (español)
					{
						Spanish.push_back(line);
					}
					else if (ingles)
					{
						English.push_back(line);
					}
				}
			}
		}
		localized.close();
		SetCodes();
	}
	
}

void Console::SetCodes()
{
	bool inf = false;
	bool warn = false;
	bool err = false;
	bool fatl = false;
	for (int i = 0; i < Spanish.size; i++)
	{
		if (Spanish.get_at(i)->value == "INFO")
		{
			inf = true;
			warn = false;
			err = false;
			fatl = false;
		}
		else if (Spanish.get_at(i)->value == "WARNING")
		{
			inf = false;
			warn = true;
			err = false;
			fatl = false;
		}
		else if (Spanish.get_at(i)->value == "ERROR")
		{
			inf = false;
			warn = false;
			err = true;
			fatl = false;
		}
		else if (Spanish.get_at(i)->value == "FATAL")
		{
			inf = false;
			warn = false;
			err = false;
			fatl = true;
		}
		else
		{
			if (Spanish.get_at(i)->value == "{" || Spanish.get_at(i)->value == "}")
			{

			}
			else
			{
				if (inf)
				{
					ESP_INFO.push_back(Spanish.get_at(i)->value);
				}
				else if (warn)
				{
					ESP_WARN.push_back(Spanish.get_at(i)->value);
				}
				else if (err)
				{
					ESP_ERR.push_back(Spanish.get_at(i)->value);
				}
				else if (fatl)
				{
					ESP_FATL.push_back(Spanish.get_at(i)->value);
				}
			}
		}
	}
	for (int i = 0; i < English.size; i++)
	{
		if (English.get_at(i)->value == "INFO")
		{
			inf = true;
			warn = false;
			err = false;
			fatl = false;
		}
		else if (English.get_at(i)->value == "WARNING")
		{
			inf = false;
			warn = true;
			err = false;
			fatl = false;
		}
		else if (English.get_at(i)->value == "ERROR")
		{
			inf = false;
			warn = false;
			err = true;
			fatl = false;
		}
		else if (English.get_at(i)->value == "FATAL")
		{
			inf = false;
			warn = false;
			err = false;
			fatl = true;
		}
		else
		{
			if (English.get_at(i)->value == "{" || English.get_at(i)->value == "}")
			{

			}
			else
			{
				if (inf)
				{
					ENG_INFO.push_back(English.get_at(i)->value);
				}
				else if (warn)
				{
					ENG_WARN.push_back(English.get_at(i)->value);
				}
				else if (err)
				{
					ENG_ERR.push_back(English.get_at(i)->value);
				}
				else if (fatl)
				{
					ENG_FATL.push_back(English.get_at(i)->value);
				}
			}
		}
	}
}


string Console::GetDate()
{
	timer = time(NULL);
	newLocal = *localtime(&timer);
	string date = "";
	if (VerboLevel == 3)
	{
		date = "Y(" + std::to_string(newLocal.tm_year);
		date += "): M(" + std::to_string(newLocal.tm_mon);
		date += "): HR(" + std::to_string(newLocal.tm_hour);
		date += "): MIN(" + std::to_string(newLocal.tm_min);
		date += "): SEC(" + std::to_string(newLocal.tm_sec);
		date += ")";
	}
	if (VerboLevel == 2)
	{
		date = std::to_string(newLocal.tm_year) + ":" + std::to_string(newLocal.tm_mon);
		date += ":" + std::to_string(newLocal.tm_hour);
		date += ":" + std::to_string(newLocal.tm_min);
		date += ":" + std::to_string(newLocal.tm_sec);
	}
	else if (VerboLevel == 1 || VerboLevel == 0)
	{
		date = std::to_string(newLocal.tm_hour);
		date += ":" + std::to_string(newLocal.tm_min);
		date += ":" + std::to_string(newLocal.tm_sec);
	}
	return date;
}