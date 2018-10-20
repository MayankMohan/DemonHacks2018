#include "game.h"
#include "menu.h"

Game::Game(std::string _name): name(_name), window(), mainMenu(NULL){
	window.create(sf::VideoMode(800, 600), name);
	
	std::vector<std::string> menuOpts = std::vector<std::string>();
	menuOpts.push_back("Start Game");
	menuOpts.push_back("Settings");
	menuOpts.push_back("Quit");
	
	mainMenu = new Menu(menuOpts, window, sf::Vector2<double>(300, 300), sf::Vector2<double>(200, 200));
}

Game::~Game(){
	delete mainMenu;
}

void Game::run(){
	mainMenu->show();
	while(window.isOpen()){
		sf::Event event;
		
		window.clear();
		
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}else{
				switch(mainMenu->process(event)){
					case 0:
						break;
					case 1:
						break;
					case 2:
						window.close();
						break;
					default:
						break;
				}
			}
		}
		
		window.display();
	}
}


