#include "character.h"



int Character::getHealth(){
	return health;
}

bool Character::state(){
	return stunned;
}

void move(int Keys){
	/*if(event.type==sf::Event::KeyPressed){
		switch (Keys){
			case LEFT:
				position.first -= Move;
				break;
			case :
				position.first += Move;
		}
			if(event.key.code==sf::Keyboard::Left){
				position.first-=5;
			}
			if(event.key.code==sf::Keyboard::Right){
				position.first+=5;
			}
			Keys & LEFT
	}*/
	
	
}
std::pair<double,double> Character::getPosition(){
	return position;
}

sf::Rect<float> Character::getBound(){
	return sf::Rect<float>(0,0,0,0);
}