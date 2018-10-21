#include "settings.h"

static void Setting::enableVsync(){
	vSync=true;
}
static void Setting::disableVsync(){
	vSync=false;	
}
static void setResolution(sf::Vector2<int> res){
	resolution=res;
}
Setting::Setting(bool syncV, sf::Vector2<int> res){
	vSync=syncV;
	resolution=res;
	mappings=getMappins();
}
static sf::Keyboard::Key[][] getMappings(){
		{{sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S,
            sf::Keyboard::F, sf::Keyboard::C, sf::Keyboard::V, sf::Keyboard::B},
        {sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down,
            sf::Keyboard::O, sf::Keyboard::Semicolon, sf::Keyboard::L, sf::Keyboard::K}}

}



