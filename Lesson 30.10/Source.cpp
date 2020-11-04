#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include "functions.h"
#include <stdlib.h>
using namespace std;
int main() {
	bool exit = false;
	int answer = 0;
	while (exit!=true)
	{
		printMenu();
		cin >> answer;
		if (answer==0)
		{
			exit = true;
		}
		else if (answer==1)
		{
			createUser();
		}
		else if (answer==2) {
			loginMenu();
		}
	}
}