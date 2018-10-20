#pragma once

#include <SFML/Graphics.h>

class Menu{
	private:
		bool visible;
		void draw();
	public:
		Menu(int numOpt, char* opts[]);
		void show();
		void hide();
		int process(sf::Event);
}
