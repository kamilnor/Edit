
/////////////////////////////////////////////////////////////////////////
//Klasa: Edit
//Autor: Kamil Klepacz
////////////////////////////////////////////////////////////////////////

#include "edit.h"


												// wywo³anie metody readDefColor celem przypisania Polu defaultColor domyslnych kolorow konsoli
WORD Edit::defaultColor = readDefColor();



// konstruktory oraz destruktor


Edit::Edit() :
	hc(GetStdHandle(STD_OUTPUT_HANDLE))
	, textBuff("")
	, fcolor(7)
	, bcolor(0)
	, usertxtLength(1)

{
	color = bcolor + fcolor;

	c.X = 0;
	c.Y = 0;
};



Edit::Edit( std::string utxt, WORD fcol, WORD bcol, int x, int y, int ulength):
	hc(GetStdHandle(STD_OUTPUT_HANDLE))
	, textBuff(utxt)
	, fcolor(fcol)
	, bcolor(bcol * 16)
	, usertxtLength(ulength)
{

	color = bcolor + fcolor;

	c.X = x;
	c.Y = y;

};

Edit::Edit(const Edit& e) :
	hc(e.hc)
	, textBuff(e.textBuff)
	, fcolor(e.fcolor)
	, bcolor(e.fcolor)
	, color(e.fcolor)
	, c(e.c)
	, usertxtLength(e.usertxtLength)
{};



Edit::~Edit() {};


// metody klasy 



void Edit::display()
{
	color = bcolor + fcolor;						//Metoda display ustawia kolory dla konsoli i wyswietla tekst przechowywany w polu textBuff
	SetConsoleTextAttribute(hc, color);
	SetConsoleCursorPosition(hc, c);

	std::cout << textBuff;		
}


std::string Edit::userText()				// Metoda przyjmuje tekst z klawiatury i zwraca go oraz przypisuje do pola textBuff
{
	std::string buf;
	char letter;


	bool flag = true;

	
	SetConsoleCursorPosition(hc, c);					//Ustawiamy pozycje na nadan¹ przez klasê
	do													// Pêtla dzia³a kiedy flaga jest ustawiona na true
	{
		
		letter = std::cin.get();					// Pobieramy po jednym znaku z klawiatury

		if (letter == '\n')							// jesli napotkany bêdzie enter flaga zmienia siê na flase i zwracane s¹ dane
		{
			flag = false;
			textBuff = buf;
			return buf;
		}
		else
		{											// w przeciwnym wypadku do buforu dodawane s¹kolejne znaki 
			buf += letter;
		}
		
	} while (flag == true);
	textBuff = buf;
	return buf;

}

WORD Edit:: readDefColor()							//funkcja odpowiada za zaczytanie danych o pierwotnych kolorach konsoli i zwraca je w zmiennej 
{
	PCONSOLE_SCREEN_BUFFER_INFO pC = new CONSOLE_SCREEN_BUFFER_INFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), pC);
	WORD defColor = pC->wAttributes;
	delete pC;
	return defColor;
}




//gettery i settery


void Edit::setLenght(int l)
{

	usertxtLength = l;

}

void Edit::setText(std::string temptxt)
{
	textBuff = temptxt;
}

void Edit::setTextColor(colEnum chosenColor)
{
	fcolor = chosenColor;
}
void Edit::setBackgroundColor(colEnum chosenColor)
{
	bcolor = chosenColor * 16;
}

void Edit::setColor(colEnum bCol, colEnum fCol)
{
	fcolor = fCol;
	bcolor = bCol * 16;

	color = bcolor + fcolor ;

}

void Edit::setPosition(int x, int y)
{

	c.X = x;
	c.Y = y;
}

HANDLE Edit::getHandle()
{
	return hc;
}




int Edit::getLenght()
{
	return usertxtLength;
}


std::string Edit::getText()
{

	return textBuff;

}


int Edit::getTextColor()
{
	return fcolor;
}

int Edit::getBackgroundColor()
{
	return bcolor;
}

WORD Edit::getColor()
{
	return color;
}

COORD Edit::getCord()
{
	return c;
}

void Edit::setHandle(HANDLE h)
{
	hc = h;
}



//operatory

const Edit& Edit:: operator=(const Edit& e)
{
	if (this == &e)								//warunek zabezpiecza sytuacje przypisania tego samego obiektu
	{

		return *this;

	}

	else
	{
		

			c.X = e.c.X;
			c.Y = e.c.Y;

			usertxtLength = e.usertxtLength;
			textBuff = e.textBuff;
			fcolor = e.fcolor;
			bcolor = e.bcolor;
			color = e.color;

			hc = e.hc;

	}
		return *this;
	
}


//manipulator defcolor

std::ostream& defcolor(std::ostream& o)
{
													//manipulator przy u¿yciu pola defaultColor ustawia kolory konsoli na domyœlne 
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = Edit::defaultColor;
	SetConsoleTextAttribute(hc, color);
	return o;
}
