#include "menu.h"

using namespace std;

class Menu{
	private: 
		Vector<string> options;
		Vector<sf::RectangleShape> shapes;
		Vector<sf::Text> texts
		sf::RenderWindow window;
	    bool visible;
		
		void draw(){
			for(sf::RectangleShape r : shapes)
				window.draw(r);
				
			for(sf::Text t : texts)
				window.draw(t);
		}

	public:
	
		Menu(Vector<string> opts, sf::RenderWindow& w, sf::Vector2<double> top_left, sf::Vector2<double> bot_right, double space = 10): options(opt), window(w), visible(false){
			double x = top_left.x, y = top_left.y;
			double height = bot_right.y - top_left.y;
			double width = bot_right.x - top_left.y;
			double sq_height = (height - (opts.size() * (space - 1))) / opts.size();
	
			for(string s: options){
				sf::RectangleShape rectangle(sf::Vector2f(width,sq_height));
				rectangle.setPosition(x, y)
				shapes.push_back(rectangle);
				sf::Text text;
				text.setFont(font);
				text.setString(s);
				text.setPosition(x + (width * .25),y + (sq_height/2);
				text.setCharacterSize(20);
				text.setColor(sf::Color::Black);
				texts.push_back(text);
				y += space + sq_height
			}
		}

		void show(){
			visible = true;
			draw();
		}
	
		void hide(){
			visible = false;
		}
	
		int process(sf::Event event){
	
		}
}