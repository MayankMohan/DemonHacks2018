#include "menu.h"

void Menu::draw(){
	for(sf::RectangleShape r : shapes)
		window.draw(r);
		
	for(sf::Text t : texts)
		window.draw(t);
}

Menu::Menu(std::vector<std::string> opts, sf::RenderWindow& w, sf::Vector2<double> top_left, sf::Vector2<double> bot_right, double space): options(opts), window(w), visible(false), current(0){
	double x = top_left.x, y = top_left.y;
	double height = bot_right.y - top_left.y;
	double width = bot_right.x - top_left.y;
	double sq_height = (height - (opts.size() * (space - 1))) / opts.size();

	for(std::string s: options){
		sf::RectangleShape rectangle(sf::Vector2f(width,sq_height));
		rectangle.setPosition(x, y);
		shapes.push_back(rectangle);
		sf::Text text;
		//text.setFont(font);
		text.setString(s);
		text.setPosition(x + (width * .25),y + (sq_height/2));
		text.setCharacterSize(20);
		text.setColor(sf::Color::Black);
		texts.push_back(text);
		y += space + sq_height;
	}
}

void Menu::show(){
	visible = true;
	draw();
}

void Menu::hide(){
	visible = false;
}

int Menu::process(sf::Event event){
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Down){
			shapes[current].setFillColor(sf::Color(100, 250, 50));
			current++;
			if(current == options.size())
				current = 0;
			shapes[current].setFillColor(sf::Color(250, 150, 100));
			draw();
			return current;
		}else if (event.key.code == sf::Keyboard::Up){
			shapes[current].setFillColor(sf::Color(100, 250, 50));
			current--;
			if(current == -1)
				current = options.size() - 1;
			shapes[current].setFillColor(sf::Color(250, 150, 100));
			draw();
			return current;
		}else if (event.key.code == sf::Keyboard::Enter){
			return current;
		}
	}
	return -1;
}
