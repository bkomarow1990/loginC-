#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;
void createUser()
{
		ofstream file("db.txt", ofstream::app);
		string login;
		string password;
		cout << "ENTER LOGIN: ";
		cin.ignore();
		getline(cin, login);
		cout << endl;
		cout << "ENTER PASSWORD: ";
		getline(cin, password);
		cout << endl;
		file << login << endl;
		file << password << endl;
		cout << endl;
		file.close();
}
void printMenu()
{
		cout << "1. CreateUser" << endl;
		cout << "2. Login" << endl;
		cout << "0. Exit" << endl;
}
void loginMenu()
{

		ifstream file("db.txt");
		string login;
		string password;
		string current_login;
		string current_password;
		int answer;
		cout << "ENTER LOGIN: ";
		cin.ignore();
		getline(cin, login);
		cout << "ENTER PASSWORD: ";
		getline(cin, password);
		bool logined = false;
		if (file.is_open()) {
			while (!file.eof())
			{
				getline(file, current_login);
				getline(file, current_password);
				if (login == current_login && password == current_password)
				{
					logined = true;
					system("CLS");
					cout << "LOGINED AS " << current_login << endl;
					system("color A0");
					Sleep(1000);
					system("color 07");
					file.close();
				}
				/*else if (login == current_login && password!=current_password) {

				}*/

			}
		}
		file.close();
		if (logined == false)
		{
			cout << "FAILED PASSWORD, idi nahui!" << endl;
			system("color 4C");
			Sleep(1000);
			system("color 07");
			cout << "1. RELOGIN" << endl;
			cout << "0. TO MAIN MENU" << endl;
			cin >> answer;
			bool exit = false;
			if (answer == 1)
			{
				system("CLS");
				loginMenu();
			}
			else {
				system("CLS");
				while (exit != true)
				{
					printMenu();
					cin >> answer;
					if (answer == 0)
					{
						break;
					}
					else if (answer == 1)
					{
						createUser();
					}
					else if (answer == 2) {
						loginMenu();
					}
				}
			}
			/*ofstream file("db.txt", ofstream::app);
			file << login <<endl;
			file << password <<endl;
			file.close();*/
		}
	}
