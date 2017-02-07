#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <stdlib.h>

#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

using namespace std;

HANDLE hConsole, hTimer;

struct Figure
{
	short color;
	COORD Part1, Part2, Part3, Part4;
	short nom;
	short poz;
} newfig, nextfig;

struct block
{
	int egz;
	int color;
} mas[11][23];

struct Rec
{
	int score;
	string name;
	string Mode;
} tabl[11];
int Score = 0;
bool EX = false, PAUSE = false, first = true;;
string NAME = "AAA";
int figure[4][4] = { 0 };


void NextStep();
void newFigure();
void MENU();
void LineScore();
void SeveRecord();

void gotoxy(int x, int y)
{
	COORD cursorLoc;
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

void initcup()
{
	gotoxy(0, 2);
	cout << "!";
	gotoxy(11, 2);
	cout << "!     ######\ \n";
	cout << "!";
	gotoxy(11, 3);
	cout << "!     # ";
	gotoxy(22, 3);
	cout << "# \n";
	cout << "!";
	gotoxy(11, 4);
	cout << "!     # ";
	gotoxy(22, 4);
	cout << "# \n";
	cout << "!";
	gotoxy(11, 5);
	cout << "!     # ";
	gotoxy(22, 5);
	cout << "# \n";
	cout << "!";
	gotoxy(11, 6);
	cout << "!     # ";
	gotoxy(22, 6);
	cout << "# \n";
	cout << "!";
	gotoxy(11, 7);
	cout << "!     ###### \n";
	cout << "!";
	gotoxy(11, 8);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 9);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 10);
	cout << "!     Score:" << Score << "\n";
	cout << "!";
	gotoxy(11, 11);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 12);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 13);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 14);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 15);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 16);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 17);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 18);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 19);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 20);
	cout << "! \n";
	cout << "!";
	gotoxy(11, 21);
	cout << "! \n";
	cout << "!==========!\n";
	gotoxy(0, 0);
	cout << "                        \n";
	cout << "                        \n";
}

void NextStep()
{
	nextfig.color = rand() % 15+1;
	SetConsoleTextAttribute(hConsole, nextfig.color);
	nextfig.nom = rand() % 7 + 1;
	nextfig.poz = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			figure[j][i] = 0;
	switch (nextfig.nom)
		{

			case 1:

				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[2][2] = nextfig.nom;
				figure[2][3] = nextfig.nom;
				break;

			case 2:
				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[1][2] = nextfig.nom;
				figure[1][3] = nextfig.nom;
				break;

			case 3:
				figure[1][0] = nextfig.nom;
				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[2][2] = nextfig.nom;
				break;

			case 4:
				figure[2][0] = nextfig.nom;
				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[1][2] = nextfig.nom;
				break;

			case 5:
				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[1][2] = nextfig.nom;
				figure[2][2] = nextfig.nom;
				break;

			case 6:
				figure[1][0] = nextfig.nom;
				figure[1][1] = nextfig.nom;
				figure[1][2] = nextfig.nom;
				figure[1][3] = nextfig.nom;
				break;
			case 7:
				figure[1][1] = nextfig.nom;
				figure[2][1] = nextfig.nom;
				figure[2][2] = nextfig.nom;
				figure[3][1] = nextfig.nom;
				break;
		}
	int l = 3;
	gotoxy(18, l);
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				{
					if (figure[j][i] == 0)
						cout << ' ';
					else
						cout << (char)219;
				}
			gotoxy(18, ++l);
		}
	SetConsoleTextAttribute(hConsole, newfig.color);
}

void newFigure()
{
	LineScore();
	newfig = nextfig;
	SetConsoleTextAttribute(hConsole, newfig.color);
	switch (newfig.nom)
		{
			case 1:
				if (mas[5][0].egz != 10 &&
				        mas[6][0].egz != 10 &&
				        mas[6][1].egz != 10 &&
				        mas[6][2].egz != 10)
					{
						mas[5][0].egz = newfig.nom;
						mas[6][0].egz = newfig.nom;
						mas[6][1].egz = newfig.nom;
						mas[6][2].egz = newfig.nom;
						newfig.Part1.X = 5;
						newfig.Part1.Y = 0;
						newfig.Part2.X = 6;
						newfig.Part2.Y = 0;
						newfig.Part3.X = 6;
						newfig.Part3.Y = 1;
						newfig.Part4.X = 6;
						newfig.Part4.Y = 2;
					}
				break;

			case 2:
				if (mas[5][0].egz != 10 &&
				        mas[6][0].egz != 10 &&
				        mas[5][1].egz != 10 &&
				        mas[5][2].egz != 10)
					{
						mas[5][0].egz = newfig.nom;
						mas[6][0].egz = newfig.nom;
						mas[5][1].egz = newfig.nom;
						mas[5][2].egz = newfig.nom;
						newfig.Part2.X = 5;
						newfig.Part2.Y = 0;
						newfig.Part1.X = 6;
						newfig.Part1.Y = 0;
						newfig.Part3.X = 5;
						newfig.Part3.Y = 1;
						newfig.Part4.X = 5;
						newfig.Part4.Y = 2;
					}
				break;

			case 3:
				if (mas[5][0].egz != 10 &&
				        mas[5][0].egz != 10 &&
				        mas[6][1].egz != 10 &&
				        mas[6][2].egz != 10)
					{
						mas[5][0].egz = newfig.nom;
						mas[5][1].egz = newfig.nom;
						mas[6][1].egz = newfig.nom;
						mas[6][2].egz = newfig.nom;
						newfig.Part1.X = 5;
						newfig.Part1.Y = 0;
						newfig.Part2.X = 5;
						newfig.Part2.Y = 1;
						newfig.Part3.X = 6;
						newfig.Part3.Y = 1;
						newfig.Part4.X = 6;
						newfig.Part4.Y = 2;
					}
				break;

			case 4:
				if (mas[6][0].egz != 10 &&
				        mas[5][1].egz != 10 &&
				        mas[6][1].egz != 10 &&
				        mas[5][2].egz != 10)
					{
						mas[6][0].egz = newfig.nom;
						mas[5][1].egz = newfig.nom;
						mas[6][1].egz = newfig.nom;
						mas[5][2].egz = newfig.nom;
						newfig.Part1.X = 6;
						newfig.Part1.Y = 0;
						newfig.Part3.X = 5;
						newfig.Part3.Y = 1;
						newfig.Part2.X = 6;
						newfig.Part2.Y = 1;
						newfig.Part4.X = 5;
						newfig.Part4.Y = 2;
					}
				break;

			case 5:
				if (mas[5][1].egz != 10 &&
				        mas[6][1].egz != 10 &&
				        mas[5][2].egz != 10 &&
				        mas[6][2].egz != 10)
					{
						mas[5][1].egz = newfig.nom;
						mas[6][1].egz = newfig.nom;
						mas[5][2].egz = newfig.nom;
						mas[6][2].egz = newfig.nom;
						newfig.Part1.X = 5;
						newfig.Part1.Y = 1;
						newfig.Part2.X = 6;
						newfig.Part2.Y = 1;
						newfig.Part3.X = 5;
						newfig.Part3.Y = 2;
						newfig.Part4.X = 6;
						newfig.Part4.Y = 2;
					}
				break;

			case 6:
				if (mas[5][0].egz != 10 &&
				        mas[5][1].egz != 10 &&
				        mas[5][2].egz != 10 &&
				        mas[5][3].egz != 10)
					{
						mas[5][0].egz = newfig.nom;
						mas[5][1].egz = newfig.nom;
						mas[5][2].egz = newfig.nom;
						mas[5][3].egz = newfig.nom;
						newfig.Part1.X = 5;
						newfig.Part1.Y = 0;
						newfig.Part2.X = 5;
						newfig.Part2.Y = 1;
						newfig.Part3.X = 5;
						newfig.Part3.Y = 2;
						newfig.Part4.X = 5;
						newfig.Part4.Y = 3;
					}
				break;

			case 7:
				if (mas[5][0].egz != 10 &&
				        mas[6][0].egz != 10 &&
				        mas[6][1].egz != 10 &&
				        mas[7][0].egz != 10)
					{
						mas[5][0].egz = newfig.nom;
						mas[6][0].egz = newfig.nom;
						mas[6][1].egz = newfig.nom;
						mas[7][0].egz = newfig.nom;
						newfig.Part1.X = 5;
						newfig.Part1.Y = 0;
						newfig.Part2.X = 6;
						newfig.Part2.Y = 0;
						newfig.Part4.X = 6;
						newfig.Part4.Y = 1;
						newfig.Part3.X = 7;
						newfig.Part3.Y = 0;
					}
				break;
		}
	if (EX && rand() % 100<5)
		{
			int n = rand() % 11+1, h = 0;
			while (mas[n][h].egz != 10 && h<22)
				h++;
			gotoxy(n, h - 3);
			cout << (char)219;
			Sleep(500);
			gotoxy(n, h - 3);
			cout << " ";
			gotoxy(n, h - 2);
			cout << (char)219;
			Sleep(500);
			gotoxy(n, h - 2);
			cout << " ";
			gotoxy(n, h - 1);
			cout << (char)219;
			mas[n][h - 1].egz = 10;
			mas[n][h - 1].color = newfig.color;
		}
	SetConsoleCursorPosition(hConsole, newfig.Part1);
	cout << (char)219;
	SetConsoleCursorPosition(hConsole, newfig.Part2);
	cout << (char)219;
	SetConsoleCursorPosition(hConsole, newfig.Part3);
	cout << (char)219;
	SetConsoleCursorPosition(hConsole, newfig.Part4);
	cout << (char)219;
}

void moveL()
{
	if (mas[newfig.Part1.X - 1][newfig.Part1.Y].egz != 10 &&
	        mas[newfig.Part2.X - 1][newfig.Part2.Y].egz != 10 &&
	        mas[newfig.Part3.X - 1][newfig.Part3.Y].egz != 10 &&
	        mas[newfig.Part4.X - 1][newfig.Part4.Y].egz != 10 &&
	        newfig.Part1.X - 1 > 0 &&
	        newfig.Part2.X - 1 > 0 &&
	        newfig.Part3.X - 1 > 0 &&
	        newfig.Part4.X - 1 > 0)
		{
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << ' ';
			mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
			newfig.Part1.X--;
			newfig.Part2.X--;
			newfig.Part3.X--;
			newfig.Part4.X--;
			mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << (char)219;
		}
}

void moveR()
{
	if (mas[newfig.Part1.X + 1][newfig.Part1.Y].egz != 10 &&
	        mas[newfig.Part2.X + 1][newfig.Part2.Y].egz != 10 &&
	        mas[newfig.Part3.X + 1][newfig.Part3.Y].egz != 10 &&
	        mas[newfig.Part4.X + 1][newfig.Part4.Y].egz != 10 &&
	        newfig.Part1.X + 1 < 11 &&
	        newfig.Part2.X + 1 < 11 &&
	        newfig.Part3.X + 1 < 11 &&
	        newfig.Part4.X + 1 < 11)
		{
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << ' ';
			mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
			newfig.Part1.X++;
			newfig.Part2.X++;
			newfig.Part3.X++;
			newfig.Part4.X++;
			mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << (char)219;
		}
}

void Rotate()
{
	switch (newfig.nom)
		{
			case 1:
				switch (newfig.poz % 4)
					{
						case 0:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y].egz != 10 &&
							        mas[newfig.Part2.X][newfig.Part2.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y].egz != 10 &&
							        mas[newfig.Part4.X - 2][newfig.Part4.Y - 1].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part2.Y + 1 < 22 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part4.X - 2 > 0 &&
							        newfig.Part4.Y - 1 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part2.Y++;
									newfig.Part3.X--;
									newfig.Part4.X -= 2;
									newfig.Part4.Y--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part2.X - 1][newfig.Part2.Y].egz != 10 &&
							        mas[newfig.Part3.X][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 1][newfig.Part4.Y - 2].egz != 10 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part2.X - 1 > 0 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X + 1 < 11 &&
							        newfig.Part4.Y - 2 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y++;
									newfig.Part2.X--;
									newfig.Part3.Y--;
									newfig.Part4.X++;
									newfig.Part4.Y -= 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 2:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y].egz != 10 &&
							        mas[newfig.Part2.X][newfig.Part2.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y].egz != 10 &&
							        mas[newfig.Part4.X + 2][newfig.Part4.Y + 1].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part2.Y - 1 > 0 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part4.X + 2 < 11 &&
							        newfig.Part4.Y + 1 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part2.Y--;
									newfig.Part3.X++;
									newfig.Part4.X += 2;
									newfig.Part4.Y++;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 3:
							if (mas[newfig.Part1.X][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part2.X + 1][newfig.Part2.Y].egz != 10 &&
							        mas[newfig.Part3.X][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 1][newfig.Part4.Y + 2].egz != 10 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part2.X + 1 < 11 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X - 1 > 0 &&
							        newfig.Part4.Y + 2 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y--;
									newfig.Part2.X++;
									newfig.Part3.Y++;
									newfig.Part4.X--;
									newfig.Part4.Y += 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
				break;
			case 2:
				switch (newfig.poz % 4)
					{
						case 0:
							if (mas[newfig.Part1.X][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part2.X + 1][newfig.Part2.Y].egz != 10 &&
							        mas[newfig.Part3.X][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X - 1][newfig.Part4.Y - 2].egz != 10 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part2.X + 1 < 11 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X - 1 > 0 &&
							        newfig.Part4.Y - 2 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y++;
									newfig.Part2.X++;
									newfig.Part3.Y--;
									newfig.Part4.Y -= 2;
									newfig.Part4.X--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y].egz != 10 &&
							        mas[newfig.Part2.X][newfig.Part2.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y].egz != 10 &&
							        mas[newfig.Part4.X + 2][newfig.Part4.Y - 1].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part2.Y + 1 < 22 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part4.X + 2 < 11 &&
							        newfig.Part4.Y - 1 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part2.Y++;
									newfig.Part3.X++;
									newfig.Part4.X += 2;
									newfig.Part4.Y--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 2:
							if (mas[newfig.Part1.X][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part2.X - 1][newfig.Part2.Y].egz != 10 &&
							        mas[newfig.Part3.X][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X + 1][newfig.Part4.Y + 2].egz != 10 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part2.X - 1 > 0 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X + 1 < 11 &&
							        newfig.Part4.Y + 2 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y--;
									newfig.Part2.X--;
									newfig.Part3.Y++;
									newfig.Part4.X++;
									newfig.Part4.Y += 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 3:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y].egz != 10 &&
							        mas[newfig.Part2.X][newfig.Part2.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y].egz != 10 &&
							        mas[newfig.Part4.X - 2][newfig.Part4.Y + 1].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part2.Y - 1 > 0 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part4.X - 2 > 0 &&
							        newfig.Part4.Y + 1 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part2.Y--;
									newfig.Part3.X--;
									newfig.Part4.X -= 2;
									newfig.Part4.Y++;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
				break;
			case 3:
				switch (newfig.poz % 2)
					{
						case 0:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 2][newfig.Part4.Y].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X - 2 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part1.Y++;
									newfig.Part3.X--;
									newfig.Part3.Y++;
									newfig.Part4.X -= 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 2][newfig.Part4.Y].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X + 2 < 11)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part1.Y--;
									newfig.Part3.X++;
									newfig.Part3.Y--;
									newfig.Part4.X += 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
				break;
			case 4:
				switch (newfig.poz % 2)
					{
						case 0:
							if (mas[newfig.Part1.X][newfig.Part1.Y + 2].egz != 10 &&
							        mas[newfig.Part2.X - 1][newfig.Part2.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 1][newfig.Part4.Y - 1].egz != 10 &&
							        newfig.Part1.Y + 2 < 22 &&
							        newfig.Part2.X - 1 > 0 &&
							        newfig.Part2.Y + 1 < 22 &&
							        newfig.Part4.X - 1 > 0 &&
							        newfig.Part4.Y - 1 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y += 2;
									newfig.Part2.X--;
									newfig.Part2.Y++;
									newfig.Part4.X--;
									newfig.Part4.Y--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X][newfig.Part1.Y - 2].egz != 10 &&
							        mas[newfig.Part2.X + 1][newfig.Part2.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 1][newfig.Part4.Y + 1].egz != 10 &&
							        newfig.Part1.Y - 2 > 0 &&
							        newfig.Part2.X + 1 < 11 &&
							        newfig.Part2.Y - 1 > 0 &&
							        newfig.Part4.X + 1 < 11 &&
							        newfig.Part4.Y + 1 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.Y -= 2;
									newfig.Part2.X++;
									newfig.Part2.Y--;
									newfig.Part4.X++;
									newfig.Part4.Y++;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
				break;
			case 6:
				switch (newfig.poz % 2)
					{
						case 0:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 2][newfig.Part4.Y - 2].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X + 2 < 11 &&
							        newfig.Part4.Y - 2 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part1.Y++;
									newfig.Part3.X++;
									newfig.Part3.Y--;
									newfig.Part4.X += 2;
									newfig.Part4.Y -= 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 2][newfig.Part4.Y + 2].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X - 2 > 0 &&
							        newfig.Part4.Y + 2 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part1.Y--;
									newfig.Part3.X--;
									newfig.Part3.Y++;
									newfig.Part4.X -= 2;
									newfig.Part4.Y += 2;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
				break;
			case 7:
				switch (newfig.poz % 4)
					{
						case 0:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 1][newfig.Part4.Y - 1].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X - 1 > 0 &&
							        newfig.Part4.Y - 1 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part1.Y--;
									newfig.Part3.X--;
									newfig.Part3.Y++;
									newfig.Part4.X--;
									newfig.Part4.Y--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 1:
							if (mas[newfig.Part1.X + 1][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X - 1][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 1][newfig.Part4.Y - 1].egz != 10 &&
							        newfig.Part1.X + 1 < 11 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part3.X - 1 > 0 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X + 1 < 11 &&
							        newfig.Part4.Y - 1 > 0)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X++;
									newfig.Part1.Y++;
									newfig.Part3.X--;
									newfig.Part3.Y--;
									newfig.Part4.X++;
									newfig.Part4.Y--;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 2:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y + 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y - 1].egz != 10 &&
							        mas[newfig.Part4.X + 1][newfig.Part4.Y + 1].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part1.Y + 1 < 22 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part3.Y - 1 > 0 &&
							        newfig.Part4.X + 1 < 11 &&
							        newfig.Part4.Y + 1 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part1.Y++;
									newfig.Part3.X++;
									newfig.Part3.Y--;
									newfig.Part4.X++;
									newfig.Part4.Y++;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
						case 3:
							if (mas[newfig.Part1.X - 1][newfig.Part1.Y - 1].egz != 10 &&
							        mas[newfig.Part3.X + 1][newfig.Part3.Y + 1].egz != 10 &&
							        mas[newfig.Part4.X - 1][newfig.Part4.Y + 1].egz != 10 &&
							        newfig.Part1.X - 1 > 0 &&
							        newfig.Part1.Y - 1 > 0 &&
							        newfig.Part3.X + 1 < 11 &&
							        newfig.Part3.Y + 1 < 22 &&
							        newfig.Part4.X - 1 > 0 &&
							        newfig.Part4.Y + 1 < 22)
								{
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << ' ';
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << ' ';
									mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
									newfig.Part1.X--;
									newfig.Part1.Y--;
									newfig.Part3.X++;
									newfig.Part3.Y++;
									newfig.Part4.X--;
									newfig.Part4.Y++;
									mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
									mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
									mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
									mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
									newfig.poz++;
									SetConsoleCursorPosition(hConsole, newfig.Part1);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part2);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part3);
									cout << (char)219;
									SetConsoleCursorPosition(hConsole, newfig.Part4);
									cout << (char)219;
								}
							break;
					}
		}
}

void LineScore()
{
	int k = 0;
	for (int H = 22; H>2; H--)
		{
			if (mas[1][H].egz == 10 &&
			        mas[2][H].egz == 10 &&
			        mas[3][H].egz == 10 &&
			        mas[4][H].egz == 10 &&
			        mas[5][H].egz == 10 &&
			        mas[6][H].egz == 10 &&
			        mas[7][H].egz == 10 &&
			        mas[8][H].egz == 10 &&
			        mas[9][H].egz == 10 &&
			        mas[10][H].egz == 10)
				{
					k++;
					SetConsoleTextAttribute(hConsole, 12);
					gotoxy(1, H);
					cout << "!!!!!!!!!!";
					Sleep(100);
					gotoxy(1, H);
					cout << "~~~~~~~~~~";
					Sleep(100);
					gotoxy(1, H);
					cout << "^^^^^^^^^^";
					Sleep(100);
					gotoxy(1, H);
					cout << "**********";
					Sleep(100);
					gotoxy(1, H);
					cout << "          ";
					mas[1][H].egz = 0;
					mas[2][H].egz = 0;
					mas[3][H].egz = 0;
					mas[4][H].egz = 0;
					mas[5][H].egz = 0;
					mas[6][H].egz = 0;
					mas[7][H].egz = 0;
					mas[8][H].egz = 0;
					mas[9][H].egz = 0;
					mas[10][H].egz = 0;
					for (int N = H - 1; N>2; N--)
						{
							if (mas[1][N].egz == 10)
								{
									gotoxy(1, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[1][N].color);
									gotoxy(1, N + 1);
									cout << (char)219;
									mas[1][N + 1].color = mas[1][N].color;
									mas[1][N].color = 0;
									mas[1][N].egz = 0;
									mas[1][N + 1].egz = 10;
								}
							if (mas[2][N].egz == 10)
								{
									gotoxy(2, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[2][N].color);
									gotoxy(2, N + 1);
									cout << (char)219;
									mas[2][N + 1].color = mas[2][N].color;
									mas[2][N].color = 0;
									mas[2][N].egz = 0;
									mas[2][N + 1].egz = 10;
								}
							if (mas[3][N].egz == 10)
								{
									gotoxy(3, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[3][N].color);
									gotoxy(3, N + 1);
									cout << (char)219;
									mas[3][N + 1].color = mas[3][N].color;
									mas[3][N].color = 0;
									mas[3][N].egz = 0;
									mas[3][N + 1].egz = 10;
								}
							if (mas[4][N].egz == 10)
								{
									gotoxy(4, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[4][N].color);
									gotoxy(4, N + 1);
									cout << (char)219;
									mas[4][N + 1].color = mas[4][N].color;
									mas[4][N].color = 0;
									mas[4][N].egz = 0;
									mas[4][N + 1].egz = 10;
								}
							if (mas[5][N].egz == 10)
								{
									gotoxy(5, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[5][N].color);
									gotoxy(5, N + 1);
									cout << (char)219;
									mas[5][N + 1].color = mas[5][N].color;
									mas[5][N].color = 0;
									mas[5][N].egz = 0;
									mas[5][N + 1].egz = 10;
								}
							if (mas[6][N].egz == 10)
								{
									gotoxy(6, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[6][N].color);
									gotoxy(6, N + 1);
									cout << (char)219;
									mas[6][N + 1].color = mas[6][N].color;
									mas[6][N].color = 0;
									mas[6][N].egz = 0;
									mas[6][N + 1].egz = 10;
								}
							if (mas[7][N].egz == 10)
								{
									gotoxy(7, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[7][N].color);
									gotoxy(7, N + 1);
									cout << (char)219;
									mas[7][N + 1].color = mas[7][N].color;
									mas[7][N].color = 0;
									mas[7][N].egz = 0;
									mas[7][N + 1].egz = 10;
								}
							if (mas[8][N].egz == 10)
								{
									gotoxy(8, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[8][N].color);
									gotoxy(8, N + 1);
									cout << (char)219;
									mas[8][N + 1].color = mas[8][N].color;
									mas[8][N].color = 0;
									mas[8][N].egz = 0;
									mas[8][N + 1].egz = 10;
								}
							if (mas[9][N].egz == 10)
								{
									gotoxy(9, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[9][N].color);
									gotoxy(9, N + 1);
									cout << (char)219;
									mas[9][N + 1].color = mas[9][N].color;
									mas[9][N].color = 0;
									mas[9][N].egz = 0;
									mas[9][N + 1].egz = 10;
								}
							if (mas[10][N].egz == 10)
								{
									gotoxy(10, N);
									cout << " ";
									SetConsoleTextAttribute(hConsole, mas[10][N].color);
									gotoxy(10, N + 1);
									cout << (char)219;
									mas[10][N + 1].color = mas[10][N].color;
									mas[10][N].color = 0;
									mas[10][N].egz = 0;
									mas[10][N + 1].egz = 10;
								}
							H++;
						}
					SetConsoleTextAttribute(hConsole, 10);
					initcup();
					for (int i = 1; i < 11; i++)
						{
							for (int j = 0; j < 22; j++)
								{
									if (mas[i][j].egz == 0)
										{
											gotoxy(i, j);
											cout << " ";
										}
									else
										{
											SetConsoleTextAttribute(hConsole, mas[i][j].color);
											gotoxy(i, j);
											cout << (char)219;
										}
								}
						}
					Score += k * 100;
					gotoxy(23, 10);
					SetConsoleTextAttribute(hConsole, 10);
					cout << Score;
				}
		}

}

void Bubble()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 10 - i; j++)
			if (tabl[j].score < tabl[j + 1].score)
				{
					Rec buf = tabl[j];
					tabl[j] = tabl[j + 1];
					tabl[j + 1] = buf;
				}
}

void SaveRecord()
{
	ifstream iRecord;
	ofstream oRecord;
	for (int i = 0; i<10; i++)
		{
			tabl[i].score = 0;
			tabl[i].name = "AAA";
			tabl[i].Mode = "Normal";
		}
	iRecord.open("Records.txt");
	for (int i = 0; i<10; i++)
		{
			iRecord >> tabl[i].score >> tabl[i].name >> tabl[i].Mode;
		}
	iRecord.close();
	tabl[10].name = NAME;
	tabl[10].score = Score;
	if (EX)
		tabl[10].Mode = "Extendet";
	else
		tabl[10].Mode = "Normal";
	Bubble();
	remove("Records.txt");
	oRecord.open("Records.txt");
	for (int i = 0; i<10; i++)
		{
			oRecord << tabl[i].score << "\t" << tabl[i].name << "\t" << tabl[i].Mode << endl;
		}
	oRecord.close();
}

void DownTimer()
{
	if (mas[newfig.Part1.X][newfig.Part1.Y + 1].egz != 10 &&
	        mas[newfig.Part2.X][newfig.Part2.Y + 1].egz != 10 &&
	        mas[newfig.Part3.X][newfig.Part3.Y + 1].egz != 10 &&
	        mas[newfig.Part4.X][newfig.Part4.Y + 1].egz != 10 &&
	        newfig.Part1.Y + 1 < 22 &&
	        newfig.Part2.Y + 1 < 22 &&
	        newfig.Part3.Y + 1 < 22 &&
	        newfig.Part4.Y + 1 < 22)
		{
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << ' ';
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << ' ';
			mas[newfig.Part1.X][newfig.Part1.Y].egz = 0;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = 0;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = 0;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = 0;
			newfig.Part1.Y++;
			newfig.Part2.Y++;
			newfig.Part3.Y++;
			newfig.Part4.Y++;
			mas[newfig.Part1.X][newfig.Part1.Y].egz = newfig.nom;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = newfig.nom;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = newfig.nom;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = newfig.nom;
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << (char)219;
		}
	else
		{
			SetConsoleCursorPosition(hConsole, newfig.Part1);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part2);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part3);
			cout << (char)219;
			SetConsoleCursorPosition(hConsole, newfig.Part4);
			cout << (char)219;
			mas[newfig.Part1.X][newfig.Part1.Y].egz = 10;
			mas[newfig.Part2.X][newfig.Part2.Y].egz = 10;
			mas[newfig.Part3.X][newfig.Part3.Y].egz = 10;
			mas[newfig.Part4.X][newfig.Part4.Y].egz = 10;
			mas[newfig.Part1.X][newfig.Part1.Y].color = newfig.color;
			mas[newfig.Part2.X][newfig.Part2.Y].color = newfig.color;
			mas[newfig.Part3.X][newfig.Part3.Y].color = newfig.color;
			mas[newfig.Part4.X][newfig.Part4.Y].color = newfig.color;
			newFigure();
			NextStep();
		}
	if (mas[0][2].egz == 10 ||
	        mas[1][2].egz == 10 ||
	        mas[2][2].egz == 10 ||
	        mas[3][2].egz == 10 ||
	        mas[4][2].egz == 10 ||
	        mas[5][2].egz == 10 ||
	        mas[6][2].egz == 10 ||
	        mas[7][2].egz == 10 ||
	        mas[8][2].egz == 10 ||
	        mas[9][2].egz == 10)
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 14);
			cout << "&&&&&&&&&&&&&&&&&&&&&&&\n&    &&    && &&& &   &\n& &&&&& && &&  &  & &&&\n& &  &&    && & & &   &\n& && && && && &&& & &&&\n&    && && && &&& &   &\n&&&&&&&&&&&&&&&&&&&&&&&\n&&&&&&&&&&&&&&&&&&&&&&\n&    && & &&   &&    &\n& && && & && &&&& && &\n& && && & &&   &&    &\n& && &&   && &&&& & &&\n&    &&& &&&   && & &&\n&&&&&&&&&&&&&&&&&&&&&&\n";
			cout << "\n\nScore: " << Score;
			SaveRecord();
			_getch();
			system("CLS");
			first = true;
			MENU();
		}
}

void Normal()
{
	PAUSE = false;
	cout << "Enter your name: ";
	cin >> NAME;
	system("cls");
	for (int i = 1; i<11; i++)
		for (int j = 0; j<22; j++)
			{
				mas[i][j].egz = 0;
				mas[i][j].color = 0;
			}
	for (int j = 3; j < 22; j++)
		mas[0][j].egz = 10;
	Score = 0;
	SetConsoleTextAttribute(hConsole, 10);
	initcup();
	NextStep();
	newFigure();
	SetConsoleTextAttribute(hConsole, 10);
	initcup();
	NextStep();
	while (mas[0][2].egz != 10 &&
	        mas[1][2].egz != 10 &&
	        mas[2][2].egz != 10 &&
	        mas[3][2].egz != 10 &&
	        mas[4][2].egz != 10 &&
	        mas[5][2].egz != 10 &&
	        mas[6][2].egz != 10 &&
	        mas[7][2].egz != 10 &&
	        mas[8][2].egz != 10 &&
	        mas[9][2].egz != 10 && !PAUSE)
		{
			while (_kbhit())
				{
					switch (_getch())
						{
							case UP_ARROW:
								Rotate();
								break;
							case DOWN_ARROW:
								DownTimer();
								break;
							case LEFT_ARROW:
								moveL();
								break;
							case RIGHT_ARROW:
								moveR();
								break;
							case VK_ESCAPE:
								first = false;
								system("cls");
								MENU();
								break;
						}
					Sleep(25);
				}
			SetConsoleTextAttribute(hConsole, 10);
			gotoxy(newfig.Part1.X,22);
			cout<<"^";
			gotoxy(newfig.Part2.X,22);
			cout<<"^";
			gotoxy(newfig.Part3.X,22);
			cout<<"^";
			gotoxy(newfig.Part4.X,22);
			cout<<"^";

			gotoxy(0,newfig.Part1.Y);
			cout<<">";
			gotoxy(0,newfig.Part2.Y);
			cout<<">";
			gotoxy(0,newfig.Part3.Y);
			cout<<">";
			gotoxy(0,newfig.Part4.Y);
			cout<<">";

			gotoxy(11,newfig.Part1.Y);
			cout<<"<";
			gotoxy(11,newfig.Part2.Y);
			cout<<"<";
			gotoxy(11,newfig.Part3.Y);
			cout<<"<";
			gotoxy(11,newfig.Part4.Y);
			cout<<"<";
			gotoxy(0,0);
			cout<<" ";
			gotoxy(0,1);
			cout<<" ";
			gotoxy(11,0);
			cout<<" ";
			gotoxy(11,1);
			cout<<" ";
			Sleep(500);
			initcup();
			SetConsoleTextAttribute(hConsole, newfig.color);
			DownTimer();
		}
}

void About()
{
	system("CLS");
	cout << "Tetris v1.5\n";
	cout << "Was made by\nSavchenko Anatolii\n";
	cout << "I am working to Debug.\n";
	cout << "I hope you enjoy my game!\n";
	cout << "(I worked very hard\nto create this application\nso please do not judge\nstrictly).\n";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Controls:\nUP-Rotate.\nDOWN-Boost.\nLEFT-Move left.\nRIGHT-Move right.\nESCAPE-Pause.\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout<<"Extendet mode:\nWith a probabbility of 5%\nfor each figure generates\nat random line a block.";
	_getch();
	system("CLS");
	MENU();
}

void Records()
{
	ifstream iRecord;
	ofstream oRecord;
	for (int i = 0; i<10; i++)
		{
			tabl[i].score = 0;
			tabl[i].name = "AAA";
			tabl[i].Mode = "Normal";
		}
	iRecord.open("Records.txt");
	for (int i = 0; i<10; i++)
		{
			iRecord >> tabl[i].score >> tabl[i].name >> tabl[i].Mode;
		}
	iRecord.close();
	for (int i = 0; i<10; i++)
		{
			cout << tabl[i].score << "\t" << tabl[i].name << "\t" << tabl[i].Mode << endl;
		}
	remove("Records.txt");
	oRecord.open("Records.txt");
	for (int i = 0; i<10; i++)
		{
			oRecord << tabl[i].score << "\t" << tabl[i].name << "\t" << tabl[i].Mode << endl;
		}
	oRecord.close();
	_getch();
	system("CLS");
	MENU();
}

void MENU()
{
	SetConsoleTextAttribute(hConsole, 5);
	gotoxy(10, 0);
	cout << "TETRIS";
	if( first == false)
		SetConsoleTextAttribute(hConsole, 9);
	else
		SetConsoleTextAttribute(hConsole, 8);
	gotoxy(1, 1);
	cout << "RESUME";
	SetConsoleTextAttribute(hConsole, 11);
	gotoxy(1, 2);
	cout << "NORMAL MODE";
	SetConsoleTextAttribute(hConsole, 10);
	gotoxy(1, 3);
	cout << "EXTENDET MODE";
	SetConsoleTextAttribute(hConsole, 14);
	gotoxy(1, 4);
	cout << "RECORDS";
	SetConsoleTextAttribute(hConsole, 12);
	gotoxy(1, 5);
	cout << "ABOUT";
	SetConsoleTextAttribute(hConsole, 4);
	gotoxy(1, 6);
	cout << "EXIT";
	SetConsoleTextAttribute(hConsole, 5);
	gotoxy(10, 0);
	cout << "TETRIS";

	int i = 2;
	SetConsoleTextAttribute(hConsole, 11);
	if( first == false)
		{
			i=1;
			SetConsoleTextAttribute(hConsole, 9);
		}
	int KeyStroke;
	gotoxy(0, i);
	cout << '>';
	do
		{
			KeyStroke = _getch();
			gotoxy(0, i);
			cout << ' ';
			switch (KeyStroke)
				{
					case UP_ARROW:
						if (i == 1 && first == false)
							i = 6;
						else if (i == 2 && first == true)
							i = 6;
						else
							i--;
						break;
					case DOWN_ARROW:
						if (i == 6 && first == false)
							i = 1;
						else if (i == 6 && first == true)
							i = 2;
						else
							i++;
						break;
				}
			switch (i)
				{
					case 1:
						if( first == false)
							SetConsoleTextAttribute(hConsole, 9);
						else
							SetConsoleTextAttribute(hConsole, 8);
						break;
					case 2:
						SetConsoleTextAttribute(hConsole, 11);
						break;
					case 3:
						SetConsoleTextAttribute(hConsole, 10);
						break;
					case 4:
						SetConsoleTextAttribute(hConsole, 14);
						break;
					case 5:
						SetConsoleTextAttribute(hConsole, 12);
						break;
					case 6:
						SetConsoleTextAttribute(hConsole, 4);
				}
			gotoxy(0, i);
			cout << '>';
		}
	while (KeyStroke != VK_RETURN);

	system("cls");
	switch (i)
		{
			case 1:
				PAUSE = false;
				if (first)
					{
						Normal();
					}
				else
					{
						SetConsoleTextAttribute(hConsole, 10);
						initcup();
						for (int i = 1; i < 11; i++)
							{
								for (int j = 0; j < 22; j++)
									{
										if (mas[i][j].egz == 0)
											{
												gotoxy(i, j);
												cout << " ";
											}
										else
											{
												SetConsoleTextAttribute(hConsole, mas[i][j].color);
												gotoxy(i, j);
												cout << (char)219;
											}
									}
							}
						SetConsoleTextAttribute(hConsole, newfig.color);
						SetConsoleCursorPosition(hConsole, newfig.Part1);
						cout << (char)219;
						SetConsoleCursorPosition(hConsole, newfig.Part2);
						cout << (char)219;
						SetConsoleCursorPosition(hConsole, newfig.Part3);
						cout << (char)219;
						SetConsoleCursorPosition(hConsole, newfig.Part4);
						cout << (char)219;
						SetConsoleTextAttribute(hConsole, 10);
						initcup();
						SetConsoleTextAttribute(hConsole, nextfig.color);
						int l = 3;
						gotoxy(18, l);
						for (int i = 0; i < 4; i++)
							{
								for (int j = 0; j < 4; j++)
									{
										if (figure[j][i] == 0)
											cout << ' ';
										else
											cout << (char)219;
									}
								gotoxy(18, ++l);
							}
						SetConsoleTextAttribute(hConsole, newfig.color);
					}
				break;
			case 2:
				EX = false;
				PAUSE = false;
				first = false;
				Normal();
				break;
			case 3:
				EX = true;
				PAUSE = false;
				Normal();
				break;
			case 4:
				Records();
				break;
			case 5:
				About();
				break;
			case 6:
				SetConsoleTextAttribute(hConsole, 0);
				exit(0);
		}
}

int main()
{

	typedef BOOL (WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
	SETCONSOLEFONT SetConsoleFont;
	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
	SetConsoleFont =(SETCONSOLEFONT) GetProcAddress(hmod, "SetConsoleFont");
	if (SetConsoleFont)
		SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),9);

	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( handle, &structCursorInfo );
	SetConsoleTitle("Tetris");

	system ("mode con cols=30 lines=25");

	srand(time(NULL));
	MENU();
	return 0;
}


