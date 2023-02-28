#include "Manager.h"
#include "Item.h"
#include <fstream>
#include <vector>
#include <iomanip>

Manager::Manager()
{
	
}

void Manager::printReward()
{
	// Current time in %Y%m%d date format
	std::time_t rawtime;
	std::tm* timeinfo;
	char buffer[80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, 80, "%Y%m%d", timeinfo);
	std::cout << "Aktualni datum je : " << buffer << std::endl;

	int dnesniIntDatum = std::stoi(buffer);

	// 	Creating reward 1.5%/2.5% 
	std::fstream soubor("predaj.txt.");
	if (soubor.is_open())
	{
		std::cout << "Odmeny (za odpracovanych 5 let a prodej noveho auta = 1,5% z ceny, za odpracovanych 5 let a prodej stareho auta = 2,5% z ceny):" << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::string jmenoPrijmeni;
			std::string spz;
			std::string boolTyp;
			std::string floatCena;
			std::string intDatum;
			std::string mezera;
			std::getline(soubor, jmenoPrijmeni);
			std::getline(soubor, spz);
			std::getline(soubor, boolTyp);
			std::getline(soubor, floatCena);
			std::getline(soubor, intDatum);
			std::getline(soubor, mezera);
			float cena = std::stof(floatCena);
			int datum = std::stoi(intDatum);

			float odmena;
			if (boolTyp == "1")
				odmena = cena * 0.015;
			else odmena = cena * 0.025;
			if (datum < dnesniIntDatum - 60000)
				std::cout << jmenoPrijmeni << " " << spz << " " << odmena << std::endl;
		}
	}
	else    std::cout << "Soubor nelze otevrit!";
	
	soubor.close();
}

void Manager::printFile()
{
	//	print of list from file, not from vector
	// vector doesn't have to be initialized 
	std::string a;
	std::fstream soubor("predaj.txt");
	if (soubor.is_open())
	{
		for (int i = 0; i < this->length; i++)
		{
			getline(soubor, a);
			std::cout << a << std::endl;
			getline(soubor, a);
			std::cout << a << std::endl;
			getline(soubor, a);
			std::cout << a << std::endl;
			getline(soubor, a);
			std::cout << a << std::endl;
			getline(soubor, a);
			std::cout << a << std::endl;
			getline(soubor, a);
			std::cout << a << std::endl;
		}
	}
	else std::cout << "soubor nelze otevrit" << std::endl;
	soubor.close();
}

void Manager::pocetZaznamu()
{
	//print count of record from vector 
	//has to be initialized 
	if (inicializace = 1)
	std::cout << "Pocet zaznamu: " << this->seznam.size() << std::endl;
	else std::cout << "Nejprve nactete databazi pomoci \"n\"" << std::endl;
}

void Manager::printVector()
{
	//print vector, has to be initialized
	if (inicializace = 1)
	{
	for (int i = 0; i < 10; i++)
		std::cout << this->seznam[i] << std::endl;
	}
	else std::cout << "Nejprve nactete databazi pomoci \"n\"" << std::endl;
}

void Manager::addToVector()
{
	//fill vector from predaj.txt
	//vector initialization
	std::fstream soubor("predaj.txt");
	std::string a;
	Item prvni;
	if (soubor.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			std::getline(soubor, a);
			prvni.meno_prizvisko = a;
			
			std::getline(soubor, a);
			prvni.spz = a;
			
			std::getline(soubor, a);
			if (a == "1")
				prvni.typ = 1;
			else prvni.typ = 0;
			
			std::getline(soubor, a);
			{
				std::cout.precision(7);
				prvni.cena = std::stof(a);
			}

			std::getline(soubor, a);
			prvni.datum = std::stoi(a);
			std::getline(soubor, a);

			this->seznam.push_back(prvni);
			this->length++;
		}	
		this->inicializace = 1;	
	}
	else std::cout << "Soubor nelze otevrit." << std::endl;
	soubor.close();		
}

void Manager::printSPZ()
{
	// print SPZ from vector
	//has to be initialized 
	if (inicializace = 1)
	{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << this->seznam[i].spz[0];
		std::cout << this->seznam[i].spz[1] << " ";
		std::cout << this->seznam[i].spz[2];
		std::cout << this->seznam[i].spz[3];
		std::cout << this->seznam[i].spz[4] << " ";
		std::cout << this->seznam[i].spz[5];
		std::cout << this->seznam[i].spz[6] << std::endl;
	}
	} 
	else std::cout << "Nejprve nactete databazi pomoci \"n\"" << std::endl;
}

void Manager::printPalyndrom()
{
	// print palindrome (SPZ) if there is one
	// initialization needed
	if (inicializace = 1)
	{
	std::string tmp;
	for (int i = 0; i < length; i++)
	{
		tmp = this->seznam[i].spz;
		
		if (tmp[0] == tmp[6] && tmp[1] == tmp[5])
			std::cout << tmp[0] << tmp[1] << std::endl;
	}
	}
	else std::cout << "Nejprve nactete databazi pomoci \"n\"" << std::endl;
}
// Nejsem schopny vymyslet algoritmus, resp vymyslet ano, ale ne napsat ho
//______________________________________________________
/*void Manager::printSale()
{	
	std::string tmp1;
	std::string tmp2;
	int count1 = 0;
	int count2 = 0;
	std::vector<std::string> spz;
	std::vector<std::string> spz1;
	for (int i = 0; i < this->length; i++)
	{
		spz.push_back(seznam[i].spz);
	}
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < 2; j++)
			if (spz[i][j] == spz[i + 1][j])
				spz1.push_back(spz[i]);

	}

	//zkouska
	for (int i = 0; i < spz.size(); i++)
	{
		std::cout << spz[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < spz1.size(); i++)
	{
		std::cout << spz1[i] << " ";
	}
}
*/
std::ostream& operator<<(std::ostream& str, Item& a)
{
	//	overloading << for printing the whole list
	std::string stav;
	if (a.typ == 1)
		stav = "Nove";
	else stav = "Poskozene";
	str << "Jmeno a prijmeni: " << a.meno_prizvisko << std::endl;
	str << "SPZ: " << a.spz << std::endl;
	str << "Stav: " << stav << std::endl;
	str << std::setprecision(2) << std::fixed;
	str << "Cena: " <<  a.cena << std::endl;
	str << "Datum: " << a.datum << std::endl;

	return str;
}


