// GraphDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Property.h"

void displayMenu() {

	std::cout << "e - exit\n";
	std::cout << "h - help\n";
	std::cout << "1 - Property::chainType()\n";
	std::cout << "2 - Property::roy_Warshall()\n";
}

void choose() {

	char option;
	do {

		std::cout << "New option...\n";
		std::cin >> option;

		switch (option) {

		case 'h': displayMenu(); break;
		case '1': Property::chainType(); break;
		case '2': Property::roy_Warshall(); break;

		default: std::cout << "There is no option " << option << "\n";
		}

	} while (option != 'e');
}

int main()
{
	displayMenu();
	choose();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
