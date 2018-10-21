#include "character.h"



int Character::getHealth(){
	return health;
}

bool Character::state(){
	return stunned;
}

void move(sf::Event event){
	if(event.type==sf::Event::KeyPressed){
			if(event.key.code==sf::Keyboard::Left){
				position.first-=5;
			}
			if(event.key.code==sf::Keyboard::Right){
				position.first+=5;
			}
	}
	
	
}
pair<double,double> Character::getPosition(){
	return position;
}

