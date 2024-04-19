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
using namespace std;

int main(){
	MainMenu* menu = new MainMenu();
	Game* game=menu->displayMenu();
	if(menu->getMainMenuFlag()==false){
		return 0;
	}
	
	//AQUI continua el juegp
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
		cout<<"3.Inventory"<<endl;
		cout<<"4.Save and Exit"<<endl;
		char choice;
		cin>>choice;
		cin.ignore();

		switch(choice){
			case '1':{
				game->getPlayer()->move();
				cout<<"\n"<<"You are now at: "<<game->getPlayer()->getLocation()->getDescription()<<endl;
					 //flag=true;
				 }break;
			case '2':{
				cout<<game->getPlayer()->getLocation()->getDescription()<<endl;
				cout<<endl;
		       		//Por ahora lo dejo con la descripcion del lugar pero despues le agrego los items
				 }break;
			case '4':{
					 cout<<"Saving game.."<<endl;
					cout<<"Goodbye!"<<endl;
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

