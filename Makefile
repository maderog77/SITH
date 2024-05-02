all: ew

main.o: main.cpp
	g++ -g -c main.cpp

game.o: game.cpp game.h
	g++ -g -c game.cpp

map.o: map.cpp map.h
	g++ -g -c map.cpp

player.o: player.cpp player.h
	g++ -g -c player.cpp

item.o: item.cpp item.h
	g++ -g -c item.cpp

location.o: location.cpp location.h
	g++ -g -c location.cpp

mainMenu.o: mainMenu.cpp mainMenu.h
	g++ -g -c mainMenu.cpp


ew: main.o game.o map.o player.o item.o location.o mainMenu.o
	g++ -o ew main.o game.o map.o player.o item.o location.o mainMenu.o -ljsoncpp

clean:
	@rm -f *.o ew
