#ifndef fight_Game
#define fight_Game

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "menu.h"

class Game{
	private:
		const std::string name;
		sf::RenderWindow window;
		Menu *mainMenu;
	public:
		Game(std::string _name);
		~Game();
		void run();
		
};
#endif
