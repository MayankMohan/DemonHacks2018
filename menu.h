#ifndef fight_Menu
#define fight_Menu

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Menu{
	private: 
		std::vector<std::string> options;
		std::vector<sf::RectangleShape> shapes;
		std::vector<sf::Text> texts;
		sf::RenderWindow &window;
	    bool visible;
		int current;
		
		void draw();

	public:
		Menu(std::vector<std::string> opts, sf::RenderWindow& w, sf::Vector2<double> top_left, sf::Vector2<double> bot_right, double space = 10.0);
		void show();
		void hide();
		int process(sf::Event event);
};
#endif
