//Ryan Swint
//Fall 2021 Chapter 4
//Module 5

//A Vector of Names
//https://github.com/ryswint



#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

const int waitTime = 1000;
const int typeTime = 25;

vector<string> names;
vector<string>::iterator changeIter;
vector<string>::const_iterator readIter;
string userInput;

bool match = false;


void Report(string report, bool newLine = true)
{
	if (newLine)
	{
		cout << endl << time(NULL) << ": ";
	}

	for (int i = 0; i < report.length(); i++)
	{
		cout << report[i];
		Sleep(typeTime);
	}

	Sleep(waitTime);
}

void Success()
{
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
	system("Color 02");
	Sleep(50);
	system("Color 20");
	Sleep(50);
}

void Invalid()
{
	system("Color 40");
	Sleep(50);
	system("Color 04");
	Sleep(50);
	system("Color 40");
	Sleep(50);
	system("Color 04");
	Sleep(50);
	system("Color 40");
	Sleep(50);
	system("Color 20");
	Sleep(50);

}

void Login()
{
	string loading = "-\|/- ";
	system("Color 02");
	Report("-*H.E.R.O.S. SHIP COMPUTER SYSTEM -- NSS OPPOSITION NS1473-- MAIN BATTLE GROUP*-", 0);
	cout << endl;
	Report("SYSTEM ACCESS REQUESTED............", 1);


	Report("ACCESS KEY REQUIRED: ", 1);



	for (int i = 0; i < 10; i++)
	{


		cout << "*";
		Sleep((rand() % 400 + 1) * 2);

	}

	cout << endl;

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "\b";
			cout << loading[i];
			Sleep(200);

		}
	}

	system("Color 20");
	system("Color 02");
	system("Color 20");
	system("Color 02");


	Report("KEY VERIFIED");

	cout << endl;

	Report("INITIALIZING CONNECTION");

	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << ".";
	}
	for (int i = 0; i < 15; i++)
	{
		Sleep(50);
		cout << ".";
	}


	for (int i = 0; i < 1000; i++)
	{
		cout << endl;

		for (int i = 0; i < 75; i++)
		{

			cout << rand() % 2;


		}
	}

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		Sleep(150);
		cout << "*SYSTEM ACCESS GRANTED*";
		Sleep(150);
		system("cls");
	}

}

int main()
{
	Login();


	do
	{
		system("cls");
		system("color 20");
		Report("-*H.E.R.O.S. A Vector of Names Application*-", 0);
		cout << endl;
		Report("What would you like to do?");

		cout << endl << ("To Add A Name, Enter \"Add\"");
		cout << endl << ("To Change A Name, Enter \"Change\"");
		cout << endl << ("To Remove A Name, Enter \"Remove\"");
		cout << endl << ("To List Names, Enter \"List\"");
		cout << endl << ("To Quit, Enter \"Quit\"");
		cout << endl << endl << "Selection: ";

		cin >> userInput; 

		if (userInput == "add" || userInput == "Add")
		{
			Success();
			Report("Names In Vector:");
			for (readIter = names.begin(); readIter != names.end(); ++readIter)
			{
				Report(*readIter);
			}
			cout << endl;
			Report("What name would you like to add to the list?");
			cout << endl << endl << "Name: ";
			cin >> userInput;
			names.push_back(userInput);
			Success();
			Report(userInput + " has been added to the vector");
			cout << endl;
			Report("Names In Vector:");
			for (readIter = names.begin(); readIter != names.end(); ++readIter)
			{
				Report(*readIter);
			}
			cout << endl;
			system("pause");

		}

		else if (userInput == "change" || userInput == "Change")
		{
			Success();
			Report("What name would you like to change?");
			Report("Names In Vector:");
			for (readIter = names.begin(); readIter != names.end(); ++readIter)
			{
				Report(*readIter);
			}
			cout << endl;
			cout << endl << endl << "Name(must match case): ";
			cin >> userInput;

			for (changeIter = names.begin(); changeIter != names.end(); ++changeIter)
			{
				if (*changeIter == userInput)
				{

					match = true;
					break;
				}
				else
				{
					match = false;
				}
			}

			if (match)


			{
				Success();
				Report("What would you like to change this name to?");
				cout << endl << endl << "New Name: ";
				cin >> userInput;
				Report(*changeIter + " changed to " + userInput);
				*changeIter = userInput;
				cout << endl;
				Report("Names In Vector:");
				for (readIter = names.begin(); readIter != names.end(); ++readIter)
				{
					Report(*readIter);
				}
				cout << endl;
				system("pause");
			}

			else
			{
				Invalid();
				Report("Name Not Found!!!");
				cout << endl;
				system("pause");
			}
		}

		else if (userInput == "remove" || userInput == "Remove")
		{
			Success();
			Report("What name would you like to remove?");
			Report("Names In Vector:");
			for (readIter = names.begin(); readIter != names.end(); ++readIter)
			{
				Report(*readIter);
			}
			cout << endl;
			cout << endl << endl << "Name(must match case): ";
			cin >> userInput;
			for (changeIter = names.begin(); changeIter != names.end(); ++changeIter)
			{
				if (*changeIter == userInput)
				{

					match = true;
					break;
				}
				else
				{
					match = false;
				}
			}

			if (match)


			{
				Success();
				names.erase(changeIter);
				Report("Name Found and Destroyed!");
				cout << endl;
				Report("Names In Vector:");
				for (readIter = names.begin(); readIter != names.end(); ++readIter)
				{
					Report(*readIter);
				}

				cout << endl;
				system("pause");

			}
			else
			{
				Invalid();
				Report("Name Not Found!!!");
				cout << endl;
				system("pause");
			}

		}

		else if (userInput == "list" || userInput == "List")
		{
			Success();
			Report("Names In Vector:");
			for (readIter = names.begin(); readIter != names.end(); ++readIter)
			{
				Report(*readIter);
			}
			cout << endl;
			system("pause");
		}
		else if (userInput == "quit" || userInput == "Quit")
		{
			break;
		}
		else
		{
			Invalid();
			Report("INVALID ENTRY", 1);

		}

	} while (userInput != "quit");

}

