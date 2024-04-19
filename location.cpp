#include "location.h"
#include <map>
#include <string>

Location::Location(){
	

}

Location::Location(std::string name,std::string description){
	this->name = name;
	this->description = description;
}

std::string Location::getName(){
	return this->name;
}

std::string Location::getDescription(){
	return this->description;
}

std::map<std::string,Location*> Location::getExits(){
	return this->exits;
}

void Location::setExits(std::string direction, Location* l){
	this->exits.insert({direction,l});
}
