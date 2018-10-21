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
		pair<double,double> position;//finds position
		std::vector<Rect<float>> hitBox;//hitboc for the move
		sf::Event hit;
		
	public:
		Character();
		int getHealth();//returns health
		bool state();//returns whether or not the person has been hit
		void move(sf::Event event);
		pair<double,double> getPosition();//returns position
		
	 
 };
 #endif
 