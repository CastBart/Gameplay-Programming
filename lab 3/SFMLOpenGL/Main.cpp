



#include "Game.h"


int main(void)
{
	sf::ContextSettings settings;
	settings.depthBits = 24u;
	settings.stencilBits = 8u;
	settings.antialiasingLevel = 4u;
	settings.majorVersion = 3u;
	settings.minorVersion = 0u;
	Game& game = Game(settings);
	game.run();
}