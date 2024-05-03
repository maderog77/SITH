#include <iostream>
#include <string>
#include "player.h"
#include "location.h"
#include "item.h"
#include "game.h"
#include "gameLoad.h"
#include "map.h"
#include <ctime>
#include <unistd.h>
#include "mainMenu.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>
using namespace std;

int main(){
	MainMenu* menu = new MainMenu();
	Game* game=menu->displayMenu();
	if(menu->getMainMenuFlag()==false){
		return 0;
	}
	
	cout<<"Loading";
	cout.flush();
	for(int i=0;i<4;i++){
		for(int i=0;i<3;i++){
			cout<<".";
			cout.flush();
			sleep(1);
		}
		cout<<"\b\b\b   \b\b\b";
	}
	cout<<endl;
	cout<<endl;
	cout<<"--GAME STARTED--"<<endl;
	cout<<"Welcome! "<<game->getPlayer()->getName()<<endl;
	cout<<game->getPlayer()->getLocation()->getDescription()<<endl;

	//Action selction
	
	bool flag=false;
	while(flag==false){
		cout<<"What would you like to do?"<<endl;
		cout<<"1.Move"<<endl;
		cout<<"2.Look"<<endl;
		if(game->getPlayer()->getLocation()->getItemsFlag()==true){ 
			cout<<"3.Take Item"<<endl;
		}
		
		cout<<"4.Inventory"<<endl;
		cout<<"5.Save and Exit"<<endl;
		char choice;
		cin>>choice;
		cin.ignore();

		switch(choice){
			case '1':{
				game->getPlayer()->move();
				cout<<"\n"<<"You are now at: "<<game->getPlayer()->getLocation()->getDescription()<<endl;
				 }break;
			case '2':{
				game->getPlayer()->getLocation()->printInventory();	
				 }break;
			case '3':{
				cout<<"Which item would you like to take?"<<endl;
				 int itemChoice;
				 cin>>itemChoice;
				 cin.ignore();
				 game->getPlayer()->addItem(game->getPlayer()->getLocation()->getInventory(),itemChoice-1);	 
				 game->getPlayer()->getLocation()->removeItem(itemChoice-1);
				 }break;
			case '4':{
					 
					 cout<<"You have the following items in your inventory:"<<endl;
					 game->getPlayer()->printInventory();
				 }break;

			case '5':{
					 
					 Json::Value save;
					 Json::Value vec(Json::arrayValue);
					 list<Item*> inventory=game->getPlayer()->getInventory();
					 for(list<Item*>::iterator it=inventory.begin();it!=inventory.end();it++){
						 vec.append((*it)->getName());
					 }
					 save["player"]["name"]=game->getPlayer()->getName();
					 save["player"]["health"]=game->getPlayer()->getHealth();
					 save["player"]["location"]=game->getPlayer()->getLocation()->getName();
					 save["player"]["inventory"]=vec;

					 ofstream file("save.json");
					 file<<save;
					 file.close();
					 cout<<endl;
					 cout<<"Saving game.."<<endl;
					cout<<"Goodbye!"<<endl;//Needs more work
					flag=true;
				 }break;
			default:{
		       		cout<<"Not a valid option!"<<endl;
				cout<<endl;
				}break;
		}
	}



return 0;
}

