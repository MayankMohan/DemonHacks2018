#include<SFML/Graphics.hpp>
#include<SFML/Graphics/Drawable.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/System/Time.hpp>
#include<SFML/System.hpp>
#include<SFML/System/Thread.hpp>
#include<vector>
#include<queue>
#include<utility>


#ifndef MATCH_H
#define MATCH_H

#include "menu.h"
#include "character.h"

#define PLAYER_1		1
#define PLAYER_2		2
#define TIE				3

/**
 * Match
 * keep track of character collide, hp, location, hitbox
 * game state 
 * timer
 */
class Match
{
private:

	std::queue<sf::Drawable*> drawQueue;

	// Match clock variables
	sf::Clock match_clk;
	sf::Time match_clk_end;

	// Characters
	Character *play1;
	Character *play2;

	/**
	 * Check the time to see if the game is over
	 */
	bool checkTime();

	/**
	 * Determine which player has greater health
	 * Return 1 or 2, respectively when game is over
	 */
	int compareHealth();

	/**
	 * playIsHit
	 * calculate if the player is hit
	 */
	bool playIsHit(Character *player, std::vector<sf::Rect<float>> hitboxes);

public:
	/**
	 * Default Constructor for the match
	 * This will setup default clock to 3 minutes
	*/
	Match();

	/**
	 * Constructor for special matches
	 */
	Match(Character *play1, Character *play2,sf::Time matchtime = sf::seconds(120));

	/**
	 * updateMatch
	 * 
	 */
	int updateMatch();

	/**
	 * draw
	 */
	void draw(sf::RenderWindow *window);

	/**
	 * startMatch
	 */
	void startMatch();

	/**
	 * pauseMatch
	 *
	 */
	void pauseMatch();

	/**
	 * resumeMatch
	 */
	void resumeMatch();

	/**
	 * CountDownTime
	 * format clock time to be in the form of a timer
	 */


};
#endif