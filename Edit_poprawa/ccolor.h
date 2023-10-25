////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		plik: ccolor
//		Opis:  Plik ccolor.h zawiera manipulatory utworzone w celu obs³ugi kolorów w konsolii.
//		Autor: Kamil Klepacz
//		Data utworzenia:04.02.2021
//
//
//
//		Data modyfikacji:					Wprowadzone zmiany:
//		04.02.2021r						- dodane manipulatory red, green, blue, white
//										- dodana funkcja i manipulator setcolor
//											
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CCOLOR_H
#define CCOLOR_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>


//manipulatory 
std::ostream& red(std::ostream& o);
std::ostream& blue(std::ostream& o);
std::ostream& green(std::ostream& o);
std::ostream& white(std::ostream& o);


//funkcja oraz manipulator setcolor na bazie dokumentacji ze strony https://docs.microsoft.com/en-us/cpp/standard-library/output-stream-manipulators-with-one-argument-int-or-long?view=msvc-160
void setcolor(std::ios_base& os, WORD color);
std::_Smanip<WORD> __cdecl SetColor(WORD color);
#endif

