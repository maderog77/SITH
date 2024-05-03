#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <map>
#include "location.h"
#include <list>
#include "item.h"

class Location {
	private:
		std::string name;
		std::string description;
		std::map<std::string, Location*> exits;
		std::list<Item*> inventory;
		bool itemsFlag=false;

	public:
		Location();
		Location(std::string name, std::string description);
		std::string getName();
		std::string getDescription();
		std::map<std::string,Location*> getExits();
		std::list<Item*> getInventory();
		void printInventory();
		bool getItemsFlag();
		Item* getItembyName(std::string name);


		void setExits(std::string direction, Location* l);
		void addItem(Item* item);
		void removeItem(int pos);
		void enableItems();


		

		
};


#endif
