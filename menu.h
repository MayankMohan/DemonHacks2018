#pragma once
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Menu{
	private: 
		Vector<string> options;
		Vector<sf::RectangleShape> shapes;
		Vector<sf::Text> texts
		sf::RenderWindow window;
	    bool visible;
		void draw();

	public:
		Menu(Vector<string> opts, sf::RenderWindow& w, sf::Vector2<double> top_left, sf::Vector2<double> bot_right, double space);
		void show();
		void hide();
		int process(sf::Event event);
}