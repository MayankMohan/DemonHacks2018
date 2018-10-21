#ifndef character
#define character


#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <utility>
//#include <sprite.h>
 
 friend class Match;
 class Character {
	private:
		int health; //character health
		int stunned; // checks if character has been hit
		std::pair<double,double> position;//finds position
		sf::Rect<float> hitBox;//hitboc for the move
		vector<Rect<float>> atkhitBox;
		bool grounded;
		int lockout;
		Moveset moves;
	public:
		Character();
		int getHealth();//returns health
		bool state();//returns whether or not the person has been hit
		void move(int Keys);
		std::pair<double,double> getPosition();//returns position

		sf::Rect<float> getChrarcterBound();
		
		enum keys {LEFT=1, RIGHT=2, UP=4, DOWN=8,
					A=16, B=32, X=64, Y=128};	
	 
 };
 #endif
 