#pragma once
#include "Cube.h"


using namespace std;

class Game
{
public:
	Game();
	~Game();


	


	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	

	void update();
	void render();
	void unload();
	Vector3 m_cubePoints[8];
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;


	GLuint vbo[1];


	
	Cube m_cube[6] = {
	Cube(6),
	Cube(3),
	Cube(),
	Cube(-3),
	Cube(-6)
	
	};
	float rotationAngle = 0.0f;
};