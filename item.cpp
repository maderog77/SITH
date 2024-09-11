#include "item.h"
#include <string>

Item::Item(){}

Item::Item(std::string name,float damage){
	this->name = name;
	this->damage = damage;
}

Item::Item(std::string name, std::string description, float damage){
	this->name = name;
	this->description = description;
	this->damage = damage;
}

std::string Item::getName(){
	return this->name;
}

std::string Item::getDescription(){
	return this->description;
}

float Item::getDamage(){
	return this->damage;
}
