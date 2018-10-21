#include "menu.h"

void Menu::draw(){
	for(sf::RectangleShape *r : shapes)
		window->draw(*r);
		
	for(sf::Text *t : texts)
		window->draw(*t);
}

Menu::Menu(std::vector<std::string> opts, sf::RenderWindow *w, sf::Vector2<double> origin, sf::Vector2<double> size, sf::Font* font, double padding, sf::Vector2<sf::Color> cols): options(opts), window(w), statusColor(cols), visible(false), current(0){
	int numElem = opts.size();
	double height = (size.y - (numElem - 1) * padding) / (double)(numElem);
	double y = origin.y;
	for(std::string s: options){
		sf::RectangleShape *rectangle = new sf::RectangleShape(sf::Vector2f(size.x, height));
		rectangle->setPosition(origin.x, y);
		rectangle->setFillColor(cols.x);
		shapes.push_back(rectangle);
		sf::Text *text = new sf::Text();
		text->setFont(*font);
		text->setString(s);
		text->setPosition(origin.x, y);
		text->setCharacterSize(20);
		text->setFillColor(sf::Color::Black);
		texts.push_back(text);
		y += height + padding;
	}
	shapes[0]->setFillColor(statusColor.y);
}

Menu::~Menu(){
	for(sf::RectangleShape *r : shapes){
		delete r;
	}
	for(sf::Text *t : texts){
		delete t;
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
	if(!visible){
		return -1;
	}
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Down){
			shapes[current]->setFillColor(statusColor.x);
			current++;
			if(current == options.size())
				current = 0;
			shapes[current]->setFillColor(statusColor.y);
		}else if (event.key.code == sf::Keyboard::Up){
			shapes[current]->setFillColor(statusColor.x);
			current--;
			if(current == -1)
				current = options.size() - 1;
			shapes[current]->setFillColor(statusColor.y);
		}else if (event.key.code == sf::Keyboard::Enter){
			return current;
		}
	}
	return -1;
}
