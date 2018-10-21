#include "inputManager.h"

InputManager::InputManager(Character *c1, Character *c2, sf::Keyboard::Key mappings[2][8]): char1(c1), char2(c2){
	mappings = Settings.getMappings();
}

void InputManager::reloadMappings(){
	mappings = Settings.getMappings();
}

void process(sf::Event event[]){
	int players[2] = {0, 0};
	for(sf::Event e : event){
		if(e.type == sf::KeyPressed){
			for(int i = 0; i < 2; i++){
				int k = 1;
				for(int j = 0; j <8; j++){
					if(mappings[i][j] == e.key.code){
						players[i] = players[i] | k;
					}
					k << 1;
				}
			}
		}
	}
	
	char1->process(players[0]);
	char1->process(players[1]);
}
