#ifndef __ITEM_H__
#define __ITEM_H__
#include <iostream>

class Item
{public:
	Item();
	void vypis();
	std::string meno_prizvisko;
	std::string spz;
	bool typ;
	float cena;
	int datum;
};


#endif
