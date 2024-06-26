#include "mainMenu.h"
#include "game.h"
#include <string>
#include <iostream>
#include <map>
#include "player.h"
#include "map.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>

MainMenu::MainMenu(){}

MainMenu::MainMenu(Game* game){
    this->game = game;
}

Game* MainMenu::displayMenu(){
	
	std::cout<<"\n--WELCOME TO THE GAME--"<<std::endl;
	bool flag=false;	
	while(flag==false){
		std::cout<<"1.Start a new game"<<std::endl;
		std::cout<<"2.Load a saved game"<<std::endl;
		std::cout<<"3.Exit"<<std::endl;
		char choice;
		std::cin>>choice;
		std::cin.ignore();

		switch(choice){//Usar este switch para crear un nuevo juego o cargar uno ya existente
			       //por ahora solo se puede crear un nuevo juego, despues debe guardarlo en un json file
			case '1':{      
					 Map* gameMap=new Map();
				       Player* player=new Player();
				       std::cout<<"Enter your name: ";
				       std::string name;
				       getline(std::cin,name);
				       //cin.ignore();
				       player->setName(name);
				       player->setLocation(gameMap->getLocationbyName("Entrance"));
				       
				       Game* tempGame=new Game(gameMap->getMap(),player);
				       this->game=tempGame;
				       //print the gameMap
				       //gameMap->printMap();

				       //cout<<gameMap.find(entrance)->first.getName()<<endl;
				       flag=true;
			       }break;
			case '2':{
					 if(!std::ifstream("save.json")){
						 std::cout<<"No saved game found"<<std::endl;
						 break;
					 }
					 Map* gameMap=new Map();
					 Player* player=new Player();
					 std::ifstream file("save.json");
					 Json::Value actualJson;
					 Json::Reader reader;

					 reader.parse(file,actualJson);
					 player->setName(actualJson["player"]["name"].asString());
					 player->setLocation(gameMap->getLocationbyName(actualJson["player"]["location"].asString()));
					 std::list<std::string> items;
					 for(int i=0;i<actualJson["player"]["items"].size();i++){   //Iterator problem
						 items.push_back(actualJson["player"]["items"][i].asString());
					 
					 }

					 for(auto it:items){      //Iterator problem doesnt load the items
						 player->addItembyName(player->getLocation()->getItembyName(it)); 
						 std::cout<<it<<std::endl;
					 }
					 Game* tempGame=new Game(gameMap->getMap(),player);
					 this->game=tempGame;
					 flag=true;
					 

				 }break;
			case '3':{
					 std::cout<<"Goodbye!"<<std::endl;
					 flag=true;
					 this->mainMenuFlag=false;
				 }break;
			       default:{
					       std::cout<<"Invalid option"<<std::endl;
				       }break;
		}
	
	}
	
	return this->game;
}

Game* MainMenu::getGame(){
    return this->game;
}

bool MainMenu::getMainMenuFlag(){
    return this->mainMenuFlag;
}


