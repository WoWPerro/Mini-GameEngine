#include "Game.h"
#include <iostream>
#include <sstream> 
#include "..\Log\Console.h"
#include "lua.h"
#include "../ScriptingSystem/LuaScript.h"
#include "../ScriptingSystem/LuaContext.hpp"

ListaT<int> extractIntegerWords(std::string str)
{
	ListaT<int> Results;
	std::stringstream ss;

	/* Storing the whole string into string stream */
	ss << str;

	/* Running loop till the end of the stream */
	std::string temp;
	int found;
	while (!ss.eof())
	{

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (std::stringstream(temp) >> found)
			Results.push_back(found);
	}
	return Results;
}

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Init(Platform* platform, GameStateManager* manager)
{
	this->platform = platform;
	this->manager = manager;
	Console::Get()->PrintInfo(3);
	i = new Image();
	i->LoadImageA("../Assets/Images/Diamond-export1.png");
	t = new Text("../Assets/Fonts/8-BIT WONDER.TTF", 30, "TEST STRING ABCDEFG", { 255, 255, 0, 255 });
	t2 = new Text("../Assets/Fonts/arial.ttf", 30, "TEST STRING ABCDEFGÑ", { 255, 0, 255, 255 });
	/*LuaScript script("C:\\Dev_WoWperro\\source\\repos\\7_Trimestre\\Diseño de Sistemas de juegos\\MiniGame Engine\\Debug\\Scripts\\Test.lua");
	std::string filename = script.get<std::string>("player.filename");
	int posX = script.get<int>("player.pos.X");*/
	LuaContext lua;
	lua.writeVariable("x", 5);
	lua.executeCode("x = x + 2;");
	std::cout << lua.readVariable<int>("x") << std::endl;       // prints 7
}

void Game::Draw()
{
	if (Console::Get()->GetVerbo() >= 1)
	Console::Get()->PrintInfo(4);
	//std::cout << " Game Draw" << std::endl;
	platform->RenderClear();
	platform->DrawRect(20, 20, 20, 20);
	platform->DrawRect(50, 20, 30, 20);
	platform->DrawRect(100, 20, 40, 40);
	platform->DrawCircle(50, 50, 50, 255, 255, 255);
	platform->RenderImage(i, 100, 500, 0);
	t->Display(100,100);
	t2->Display(100, 200);
	platform->RenderPresent();
}

bool Game::Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY)
{
	if (!(keyUps->size == 0))
	{
		for (int i = 0; i < keyUps->size; i++)
		{
			int num = keyUps->get_at(i)->value;
			if (num == 27)
			{
				Console::Get()->SaveConsole();
				exit(1);
			}
		}
	}

	if (!(keyDowns->size == 0))
	{
		for (int i = 0; i < keyDowns->size; i++)
		{
			int num = keyDowns->get_at(i)->value;
		}
	}

	if (Console::Get()->GetVerbo() >= 1)
	Console::Get()->PrintInfo(5);
	//std::cout << " Game Input" << std::endl;
	return false;
}

void Game::Update()
{
	//std::cout << " Game Update" << std::endl;
	if(Console::Get()->GetVerbo() >= 1)
	Console::Get()->PrintInfo(6);
}

void Game::Close()
{
	//std::cout << " Close Init" << std::endl;
	if (Console::Get()->GetVerbo() >= 1)
	Console::Get()->PrintInfo(7);
}