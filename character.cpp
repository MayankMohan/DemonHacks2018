#include "character.h"


Character(int hp, std::pair<double,double> start,sf::Rect<float> hitbox, vector<>	)
int Character::getHealth(){
	return health;
}

bool Character::state(){
	return stunned;
}

void process(int Keys){
	bool action;
	if(!lockout && !stunned){
		Action* atk;
		action=moves.process(keys,grounded,&atk);
		if(action){
			//atk->process() todo
		}
	}	
}
std::pair<double,double> Character::getPosition(){
	return position;
}

