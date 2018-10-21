#ifndef setting
#define setting

#include #include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <utility>

class Setting {
	private:
		static sf::Vector2<int> resolution;
		static bool vSync;
		static sf::Keyboard::Key mappings [2][8];
	public:
		Setting(bool syncV, sf::Vector2<int> res);
		static void enablevSync();
		static void disablevSync();
		static void setResolution(sf::Vector2<int> res);
		static sf::Keyboard::Key[][] getMappings();//returns that big thing mayank sent me
};
#endif
	
	
	
	
	