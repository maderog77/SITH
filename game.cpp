#include "game.h"
#include "player.h"
#include "location.h"
#include <string>
#include <iostream>
#include <map>

Game::Game(){}

Game::Game(std::map<Location*,std::map<std::string,Location*>> gameMap,Player* player){
	this->player = player;
	this->gameMap = gameMap;
}

Player* Game::getPlayer(){
	return this->player;
}

std::map<Location*,std::map<std::string,Location*>> Game::getGameMap(){
	return this->gameMap;
}

void Game::setGameId(std::string gameId){
	this->gameId = gameId;
}
