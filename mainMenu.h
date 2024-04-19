#ifndef MAINMENU_H
#define MAINMENU_H
#include "game.h"
#include <string>


class MainMenu{
	private:
		Game* game;
		bool mainMenuFlag=true;

	public:
		MainMenu();
		MainMenu(Game* game);
		Game* displayMenu();
		Game* getGame();
		bool getMainMenuFlag();

};


#endif
