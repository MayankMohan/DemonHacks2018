#ifndef character
#define character


#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <utility>
//#include <sprite.h>
 
 
 class Character {
	private:
		int health; //character health
		bool stunned; // checks if character has been hit
		std::pair<double,double> position;//finds position
		std::vector<sf::Rect<float>> hitBox;//hitboc for the move
		sf::Event hit;
		
	public:
		Character();
		int getHealth();//returns health
		bool state();//returns whether or not the person has been hit
		void move(int Keys);
		std::pair<double,double> getPosition();//returns position

		sf::Rect<float> getBound();
		
		enum keys {LEFT=1, RIGHT=2, UP=4, DOWN=8,
					A=16, B=32, X=64, Y=128};	
	 
 };
 #endif
 