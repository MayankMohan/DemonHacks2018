#ifndef fight_InputManager
#define fight_InputManager

#include "settings.h"
#include "character.h"

class InputManager{
	private:
		sf::Keyboard::Key mappings[2][8];
		Character *char1;
		Character *char2;
	public:
		InputHandler(Character *c1, Character *c2, sf::Keyboard::Key mappings[2][8]);
		void reloadMappings();
		void process(sf::Event event);
}


#endif
