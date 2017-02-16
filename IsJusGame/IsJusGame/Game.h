#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "ProgramIds.h"
#include "Cube.h"



class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();

	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
private:
	Cube m_cube;
	ProgramIds m_ids;
};

#endif