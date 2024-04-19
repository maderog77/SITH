#include "player.h"
#include "location.h"
#include "item.h"
#include <string>
#include "map.h"
#include <iostream>

Player::Player(){
	this->health=100;
	Map* map=new Map();
	this->location=map->getLocationbyName("Entrance");

}

std::string Player::getName(){
	return this->name;
}

float Player::getHealth(){
	return this->health;
}

Location* Player::getLocation(){
	return this->location;
}

void Player::printInventory(){
	for(Item* item:this->inventory){
		std::cout<<item->getName()<<std::endl;
	}
}

void Player::setName(std::string name){
	this->name=name;
}

void Player::setHealth(float health){
	this->health=health;
}

void Player::setLocation(Location* location){
	this->location=location;
}

void Player::move(){
	std::cout<<"Where would you like to go?"<<std::endl;
        std::map<std::string,Location*> exits=this->location->getExits();
        for(auto it=exits.begin();it!=exits.end();it++){
                std::cout<<it->first<<": "<<it->second->getName()<<std::endl;
        }
        bool valid=false;
        std::string d;
	while(!valid){
                getline(std::cin,d);
                for(auto it=exits.begin();it!=exits.end();it++){
                        if(d==it->first){
                                valid=true;
                        }else{
                                std::cout<<"Invalid direction. Please try again."<<std::endl;
                        }
                }
        }


        for(auto it=exits.begin();it!=exits.end();it++){
                if(d==it->first){
                        this->location=it->second;
                }
        }


}


