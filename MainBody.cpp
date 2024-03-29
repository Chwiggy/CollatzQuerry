#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

//Global variable declared
int number1, number2;

//Checks for, you've guessed it, parity
bool parity(int n) {
	return n % 2 == 0;
}

//Main Calculation
void Collatz(int n) {
	if (n != 1) {
		//Parity decides our next operational step
		if (parity(n)) {
			n = n / 2;
			std::cout << n << ", ";
			//Recursion
			Collatz(n);
		}
		else {

			if (n > 715827882) {
				// If it goes over the bounds of a signed interger... Maybe I should declare an unsigned integer
				std::cout << "..." << std::endl << std::endl << "This got out of bounds!";
			}
			else {
				n = 3 * n + 1;
				std::cout << n << ", ";
				//Recursion
				Collatz(n);
			}
		}
	}
	else {
		//If its one, its one
		std::cout << "1" << std::endl << "Terminated!" << std::endl;
	}
}

void CArray(int bound) {
	int i;
	for (i = 1; i <= bound; i++) {
		Collatz(i);
	}
}

//Input test
bool validity(int n) {
	bool valid = false;


	while (!valid) {
		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Unexpected input. Please input an integer: " << std::endl;
			std::cin >> n;
		}
		else {
			valid = true;
			std::cin.clear();
		}
	}

	return valid;
}

int main()
{
	bool modeChosen = false;
	//while (!modeChosen) {
		//mode
		char mode[8];
		//char compare[8];
		std::cout << "Please, choose: Do you want to *compare* or just view a *single* series?" << std::endl;
		std::cin.getline(mode, 8);
		std::cout << std::endl;

		//mode switch

		if (strcmp(mode, "compare") == 0) {
			//terminator of the loop
			//modeChosen = true;

			//First input
			std::cout << "Please, choose your first number" << std::endl;
			std::cin >> number1;
			validity(number1);

			//Second input
			std::cout << "And your second number:" << std::endl;
			std::cin >> number2;
			validity(number2);

			system("pause");

			//Function call and bounds
			Collatz(number1);
			Collatz(number2);

			//break;

		}else if (strcmp(mode, "single") == 0) {

			//Loop-termination
			//modeChosen = true;

			//User Querry
			std::cout << "Please choose an integer i.e. a positive whole number to start your Collatz-Sequence:" << std::endl;
			std::cin >> number1;

			//Input test and main fuction call
			Collatz(validity(number1));
			
			//break;

		}
		else {

			std::cout << "undefined" << std::endl;
			
			//continue;

		}
	//}


	//About
	std::cout << std::endl << std::endl << "Programmer: Patrick N. Wilke" << std::endl << "CollatzQuery v1.3.3 September 2018" << std::endl << std::endl;


	return 0;
}

