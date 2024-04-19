#ifndef MAP_H
#define MAP_H
#include "location.h"
#include <map>
#include <string>

class Map{
	private:
		std::map<Location*,std::map<std::string,Location*>> gameMap;
	public:
		Map();
		std::map<Location*,std::map<std::string,Location*>> getMap();
		void setMap(Location* l,std::map<std::string,Location*> exits);
		void printMap();
		Location* getLocationbyName(std::string name);
};	



#endif
