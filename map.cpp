#include "map.h"
#include <map>
#include <string>
#include <iostream>
#include "location.h"

Map::Map(){
	 Location* entrance=new Location("Entrance","You are at the entrace of a spooky house");
	 Location* livingRoom=new Location("Living Room","You are in the living room, there is a couch and a TV");
	 Location* kitchen=new Location("Kitchen","You are in the kitchen, there is a fridge and a stove");
	 Location* bedroom=new Location("Bedroom","You are in the bedroom, there is a bed and a closet");
	 Location* bathroom=new Location("Bathroom","You are in the bathroom, there is a toilet and a sink");
	 Location* backyard=new Location("Backyard","You are in the backyard, there is a pool and a grill");

	 //set exits
	 entrance->setExits("north",livingRoom);
         livingRoom->setExits("south",entrance);
	 livingRoom->setExits("east",kitchen);
	 livingRoom->setExits("west",bedroom);
	 bedroom->setExits("east",livingRoom);
	 bedroom->setExits("north",bathroom);
	 bathroom->setExits("south",bedroom);
	 kitchen->setExits("west",livingRoom);
	 kitchen->setExits("north",backyard);
	 backyard->setExits("south",kitchen);

	 gameMap.insert({entrance,entrance->getExits()});
	 gameMap.insert({livingRoom,livingRoom->getExits()});
	 gameMap.insert({kitchen,kitchen->getExits()});
	 gameMap.insert({bedroom,bedroom->getExits()});
	 gameMap.insert({bathroom,bathroom->getExits()});
	 gameMap.insert({backyard,backyard->getExits()});
}

std::map<Location*,std::map<std::string,Location*>> Map::getMap(){
	return this->gameMap;
}

void Map::setMap(Location* l, std::map<std::string,Location*> exits){
	//this->gameMap->insert(std::pair<Location*,std::map<std::string,Location*>>(l,exits));
	//this->gameMap[l] = exits;
	gameMap.insert({l,exits});
}


void Map::printMap(){
	for(auto it = gameMap.begin(); it != gameMap.end(); ++it){
		std::cout << it->first->getName() << std::endl;
		for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
			std::cout << it2->first << " " << it2->second->getName() << std::endl;
		}
	}
}

Location* Map::getLocationbyName(std::string name){
	Location* loc;
	for(auto it=gameMap.begin();it!=gameMap.end();it++){
		if(it->first->getName()==name){
			loc= it->first;
		}
	}
	return loc;
}
