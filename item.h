#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item{
	private:
		std::string name;
		std::string description;
		float damage;
	public:
		Item();
		 Item(std::string name, std::string description, float damage);
		std::string getName();
		std::string getDescription();
		float getDamage();
};


#endif
