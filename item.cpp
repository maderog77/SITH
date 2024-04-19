#include "item.h"
#include <string>

std::string Item::getName(){
	return this->name;
}

std::string Item::getDescription(){
	return this->description;
}

float Item::getDamage(){
	return this->damage;
}
