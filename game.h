#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>	
#include "player.h"
#include "location.h"
#include "item.h"
#include <map>
class Game{
	private:
	Player* player;
	std::map<Location*,std::map<std::string,Location*>> gameMap;
 	std::string gameId;
	
	public:
	Game(std::map<Location*,std::map<std::string,Location*>> gameMap,Player* player);
	Game();
	Player* getPlayer();
	std::map<Location*,std::map<std::string,Location*>> getGameMap();
	void setGameId(std::string gameId);
	std::string getGameId();
};


#endif
