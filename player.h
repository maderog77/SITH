#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "location.h"
#include <iostream>
#include <list>
#include "item.h"
#include <map>

class Player {
	private:
		std::string name;
		std::list<Item*> inventory;
		float health;
		Location* location=new Location();
	public:
		Player();
		std::string getName();
		float getHealth();
		Location* getLocation();
		void printInventory();
		Item* getItembyName(std::string name);
		std::list<Item*> getInventory();

		void setName(std::string name);
		void setHealth(float health);
		void setLocation(Location* location);
		void move();
		void addItem(std::list<Item*> linventory,int pos);
		void addItembyName(Item* item);
};



#endif
