#ifndef GAMELOAD_H
#define GAMELOAD_H
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>

class GameLoad{
	private:
		Game* game;
		std::string filename;
	public:
		GameLoad();
		GameLoad(std::string fname, Game* g);
		Game* getGame();
};


#endif
