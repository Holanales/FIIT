#include <iostream>
#include <fstream>
#include <string>
#include "Manager.h"
#include "Item.h"


int main()
{
	

	Manager a;
	char menu;
	
	while (true)
	{
		std::cout << "Press \"v\" to print the list from a file." << std::endl;
		std::cout << "Press \"k\" to end." << std::endl;
		std::cout << "Press \"o\" to print a employee reward." << std::endl;
		std::cout << "Press \"n\" to initialize an array (vector), filling the vector and printing the count of records. "<< std::endl;
		std::cout << "Press \"s\" to print SPZ. " << std::endl;
		std::cout << "Press \"p\" to print a SPZ palindrome, if there is one." << std::endl;  
		std::cin >> menu;
		switch (menu) {
		case 'v':
			a.printFile();
			break;
		case 'k':
			return 0;
		case 'o':
			a.printReward();
			break;
		case 'n':
			a.addToVector();
			a.pocetZaznamu();
			a.printVector();
			break;
		case 's':
			a.printSPZ();
			break;
		case 'p':
			a.printPalyndrom();
			break;
		//case 'z':
		//	a.printSale();
		//	break;
		}
	}
	

	return 0;
}