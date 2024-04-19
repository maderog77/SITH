#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <map>
#include "location.h"
class Location {
	private:
		std::string name;
		std::string description;
		std::map<std::string, Location*> exits;
	public:
		Location();
		Location(std::string name, std::string description);
		std::string getName();
		std::string getDescription();
		std::map<std::string,Location*> getExits();


		void setExits(std::string direction, Location* l);


		

		
};


#endif
