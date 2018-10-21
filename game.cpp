#include "game.h"
#include "menu.h"
#include <cstdio>

Game::Game(std::string _name): name(_name), window(), mainMenu(NULL){
	window.create(sf::VideoMode(800, 600), name);
	
	font = new sf::Font;
	font->loadFromFile("res/arial.ttf");
	
	std::vector<std::string> menuOpts = std::vector<std::string>();
	menuOpts.push_back("Start Game");
	menuOpts.push_back("Settings");
	menuOpts.push_back("Quit");
	
	mainMenu = new Menu(menuOpts, &window, sf::Vector2<double>(300, 200), sf::Vector2<double>(200, 200), font);
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
			}else if(mainMenu->isOpen()){
				int i = mainMenu->process(event);
				printf("%i\n", i);
				switch(i){
					case 0:
						mainMenu->hide();
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
		
		mainMenu->draw();
		window.display();
	}
}


