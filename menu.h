#ifndef fight_Menu
#define fight_Menu

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Menu{
	private: 
		std::vector<std::string> options;
		std::vector<sf::RectangleShape*> shapes;
		std::vector<sf::Text*> texts;
		sf::Vector2<sf::Color> statusColor;
	    bool visible;
		int current;
		
	public:
		Menu(std::vector<std::string> opts, sf::Vector2<double> origin, sf::Vector2<double> size, sf::Font *font, double padding = 10.0, sf::Vector2<sf::Color> cols = sf::Vector2<sf::Color>(sf::Color(111, 133, 170), sf::Color(76, 142, 247)));
		~Menu();
		void show();
		void hide();
		void draw(sf::RenderWindow *window);
		bool isOpen(){return visible;}
		int process(sf::Event event);
};
#endif
