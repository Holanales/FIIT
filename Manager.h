#ifndef __MANAGER_H__
#define __MANAGER_H__
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

class Manager
{public: 
	std::vector<Item> seznam;
	int length = 0;
	bool inicializace =0;
	Manager();
	void addToVector();
	void printFile();
	void printVector();
	void printReward();
	void pocetZaznamu();
	void printSPZ();
	void printPalyndrom();
	void printSale();
};

std::ostream& operator <<(std::ostream& str,Item& a);
#endif
