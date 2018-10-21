#include "game.h"
#include "menu.h"

Game::Game(std::string _name): name(_name), window(), mainMenu(NULL){
	window.create(sf::VideoMode(800, 600), name);
	
	font = new sf::Font;
	font->loadFromFile("res/font/arial.ttf");
	
	std::vector<std::string> menuOpts = std::vector<std::string>();
	menuOpts.push_back("Start Game");
	menuOpts.push_back("Settings");
	menuOpts.push_back("Quit");
	
	mainMenu = new Menu(menuOpts, sf::Vector2<double>(300, 200), sf::Vector2<double>(200, 200), font);
}

Game::~Game(){
	delete mainMenu;
}

void Game::run(){
	mainMenu->show();
	while(window.isOpen()){
		sf::Event event;
		
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}else if(mainMenu->isOpen()){
				switch(mainMenu->process(event)){
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
		
		window.clear();
		mainMenu->draw(&window);
		window.display();
	}
}


