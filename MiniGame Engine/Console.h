#pragma once
class Console
{
public:
	static Console* Get();
private:
	Console();
	~Console();
	static Console* console;
public:
	void Print();
};