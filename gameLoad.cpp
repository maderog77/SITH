#include "gameLoad.h"
#include "game.h"
#include <string>

GameLoad::GameLoad(){ }

GameLoad::GameLoad(std::string fname,Game* g){
	this->game = g;
	this->filename = fname;
}

Game* GameLoad::getGame(){
	return this->game;
}
