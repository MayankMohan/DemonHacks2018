#include "match.h"

static sf::Time pauseTime;

Match::Match(Character *play1, Character *play2, sf::Time matchtime)
	: play1(play1), play2(play2), match_clk_end(matchtime)
{
}

/**
 * updateMatch
 * Called by game, and updates game states from given state
 * Returns 0 if all events were registered
 * Returns -1 if error occurs
 * Returns 1 or 2 to determine winner
 */
int Match::updateMatch(){
	// Timer is complete
	if (checkTime()){
		return compareHealth();
	}
	// check health
	if (!play1->getHealth()){
		return PLAYER_2;
	}else if (!play2->getHealth()) {
		return PLAYER_1;
	}

	// Update Characters

	// Adding Drawables

	return 0;
}

void Match::draw(sf::RenderWindow *window){
	while(!drawQueue.empty()){
		window->draw(*drawQueue.front());
		drawQueue.pop();
	}
}

// restart clock
// restart character position
void Match::startMatch(){
	match_clk.restart();
	pauseTime = sf::seconds(0);
}

void Match::pauseMatch() {
	pauseTime = match_clk.getElapsedTime();
}

void Match::resumeMatch() {
	match_clk.restart();
	match_clk_end = match_clk_end - pauseTime;
}

// Private Helper Functions 
bool Match::checkTime(){
	return (match_clk.getElapsedTime() > match_clk_end) ? true : false;
}

/**
 * compareHealth
 * when timer completes, check who wins
 */
int Match::compareHealth(){
	if (play1->getHealth() > play2->getHealth()) {
		return PLAYER_1;
	} else if (play1->getHealth() < play2->getHealth()) {
		return PLAYER_2;
	} else {
		return TIE;
	}
}

bool Match::playIsHit(Character *player, std::vector<sf::Rect<float>> hitboxes) {
	sf::Rect<float> plyrArea = player->getBound();	// change this
	for (sf::Rect<float> hit : hitboxes) {
		if (hit.intersects(plyrArea)){
			return true;
		}
	}
	return false;
}
