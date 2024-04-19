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

		void setName(std::string name);
		void setHealth(float health);
		void setLocation(Location* location);
		void move();
};



#endif
