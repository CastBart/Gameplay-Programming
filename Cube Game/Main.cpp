#include "Game.h"
int main(void)
{
	sf::ContextSettings settings;
	settings.depthBits = 32u;
	settings.antialiasingLevel = 24u;

	Game& game = Game(settings);
	game.run();
}