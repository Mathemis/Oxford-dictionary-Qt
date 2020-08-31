#include "Dictionary.h"
#include <windows.h>
#include <conio.h>

#define ENTER 13


void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}


void drawMenu()
{
	cout << "=================================================\n";
	cout << "\t     OXFORD ENGLISH DICTIONARY\n";
	cout << "=================================================\n";
	cout << "   1.Search for a word.\n";
	cout << "   2.Add a word to dictionary.\n";
	cout << "   3.Modify definition of a word.\n";
	cout << "   4.Remove a word from dictionary.\n";
	cout << "   5.Save current Dictionary to file.\n";
	cout << "   0.EXIT.\n";
	cout << "---------------------\n";
	textcolor(8);
	cout << "Enter your choice: ";
	textcolor(15);
}

void Menu(DictionaryInterface &Dict, int &readKey)
{
	do {
		clearScreen();
		drawMenu();
		cin >> readKey;
	} while (readKey < 0 || readKey > 5);


	if (readKey == 0)
		return;

	clearScreen();
	cout << endl;
	if (readKey == 1) {
		cin.ignore();
		string key;
		cout << "Enter word to search: ";
		getline(cin, key);
		cout << "\n";
		Dict.Search(key);
	}
	else if (readKey == 2) {
		cin.ignore();
		string key, value;
		cout << "Enter word to add: ";
		getline(cin, key);
		cout << "\nEnter definition: ";
		getline(cin, value);
		cout << "\n\n";
		Dict.Insert(key, value);
	}
	else if (readKey == 3) {
		cin.ignore();
		string key, value;
		cout << "Enter word to modify: ";
		getline(cin, key);
		cout << "\nEnter new definition: ";
		getline(cin, value);
		cout << "\n\n";
		Dict.Modify(key, value);
	}
	else if (readKey == 4) {
		cin.ignore();
		string key;
		cout << "Enter word to remove: ";
		getline(cin, key);
		cout << "\n\n";
		Dict.Remove(key);
	}
	else if (readKey == 5) {
		//cin.ignore();
		Dict.Save();
	}
	textcolor(8);
	cout << "\n\n-----------------------\n";
	cout << "Press Enter to back...";
	textcolor(15);
	char ch;
	do {
		ch = _getch();
	} while (ch != ENTER);

}

void RunDictionary(DictionaryInterface &Dict)
{
	int readKey = 0;
	do {
		Menu(Dict, readKey);
	} while (readKey);
}
