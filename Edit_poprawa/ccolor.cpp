/////////////////////////////////////////////////////////////////////////
//plik: ccolor.cpp
//Autor: Kamil Klepacz
////////////////////////////////////////////////////////////////////////

#include "ccolor.h"


std::ostream& red(std::ostream& o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_RED);
	return o;
}


std::ostream& blue(std::ostream& o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_BLUE);
	return o;
}


std::ostream& green(std::ostream& o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_GREEN);
	return o;
}


std::ostream& white(std::ostream& o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return o;
}


//funkcja oraz manipulator set kolor na bazie dokumentacji ze strony https://docs.microsoft.com/en-us/cpp/standard-library/output-stream-manipulators-with-one-argument-int-or-long?view=msvc-160

void setcolor(std::ios_base& os, WORD color)	
{
	std::ostream* pos = dynamic_cast<std::ostream*>(&os);
	if (pos)
	{
		HANDLE hc;
		hc = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hc,color);
	};
}


std::_Smanip<WORD> __cdecl SetColor(WORD color)
{
	return (std::_Smanip<WORD>(&setcolor, color));
}