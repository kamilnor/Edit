////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Klasa: Edit
//		Opis:  Klasa Edit daje mo�liwo�� operowania kolorystyk� i kursorem w konsoli.
//		Umo�liwia wprowadzanie oraz edycj� tekstu na polu tekstowym przed dodaniem go do docelowego ci�gu znak�w.
//		Autor: Kamil Klepacz
//		Data utworzenia:23.11.2020r
//
//		Data modyfikacji:					Wprowadzone zmiany:
//		06.12.2020							- Dodane konstruktory oraz destruktor
//											- Dodane metody 
//											- Pr�ba utworzenia metody userText
//	
//		04.02.2021							- przemodelowanie struktury klasy :
//												Usuni�cie dziedziczenia z powodu przerobienia klasy ccolor na pliki zawieraj�ce manipulatory,
//												Elementy z usunietej klasy ccolor przeniesione do klasy Edit i odpowiednio przebudowane
//											- Dodane settery oraz gettery
//											- dodany konstruktor kopiuj�cy
//											- dodany operator =
//											- dodano metode oraz pole umozliwiajace dzialanie manipulatora defcolor
//		
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef EDIT_H
#define EDIT_H


#include <iostream>
#include <string>
#include <Windows.h>


class Edit
{
public:

	// enumerator utworzony w celu mo�liwo�ci jednoczesnej zmiany koloru tekstu oraz t�a


	enum colEnum
	{
		Black,
		Blue,
		Green,
		Aqua,
		Red,
		Purple,
		Yellow,
		White,
		Gray,
		Light_Blue,
		Light_Green,
		Light_Aqua,
		Light_Red,
		Light_Purple,
		Light_Yellow,
		Bright_White
	};


	// konstruktory oraz destruktor


	Edit();

	Edit(std::string utxt, WORD fcol, WORD bcol, int x, int y, int ulength);

	Edit(const Edit& c);

	~Edit();


	// metody klasy 


	void display();

	std::string userText();

	static WORD readDefColor();





	//gettery i settery


	int getLenght();
	std::string getText();
	int getTextColor();
	int getBackgroundColor();
	WORD getColor();
	COORD getCord();
	HANDLE getHandle();



	void setLenght(int l);
	void setText(std::string temptxt);
	void setTextColor(colEnum chosenColor);
	void setBackgroundColor(colEnum chosenColor);
	void setColor(colEnum bCol, colEnum fCol);
	void setPosition(int x, int y);
	void setHandle(HANDLE h);
	



private:

	// pola klasy
	COORD c;
	int usertxtLength;
	HANDLE hc;
	std::string textBuff;
	int fcolor, bcolor;
	WORD color;

	



public: 

										//Pole statyczne dla danych o pierwotnym kolorze konsoli
	static  WORD defaultColor;

	//operatory

	const Edit& operator=(const Edit& e);
	
};




//manipulator defcolor
std::ostream& defcolor(std::ostream& o);

#endif
