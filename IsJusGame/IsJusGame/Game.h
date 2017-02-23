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
	void update(double);
	void render();
	void unload();
	void createCubes();
private:
	
	glm::mat4 cameraView;
	Cube m_player;
	std::vector<Cube> m_cubes;
	ProgramIds m_ids;

	sf::Time m_elapsed;
	float nextWave = 0;



};

#endif