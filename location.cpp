#include "location.h"
#include <map>
#include <string>
#include <iostream>

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

std::list<Item*> Location::getInventory(){
		return this->inventory;
}

void Location::printInventory(){
	if(this->inventory.size()!=0){
		std::cout<<"\nThis place has the following items:"<<std::endl;
		int it=1;
		for(auto i:this->inventory){
		std::cout<<it<<":"<<i->getName()<<std::endl;
		it++;
		}
		std::cout<<std::endl;
		this->itemsFlag = true;
	}else{
		std::cout<<"This place is empty"<<std::endl;
	}
}

bool Location::getItemsFlag(){
	return this->itemsFlag;
}


void Location::setExits(std::string direction, Location* l){
	this->exits.insert({direction,l});
}

void Location::addItem(Item* i){
	this->inventory.push_back(i);
}

void Location::removeItem(int pos){//terminar esta funcion
	std::list<Item*>::iterator it = this->inventory.begin();
	for(int i=0;i>pos;i++){
		it++;
	}
	this->inventory.erase(it);
}

void Location::enableItems(){
	this->itemsFlag = true;
}


