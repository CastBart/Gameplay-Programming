#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <fstream>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Vector3.h"
#include "Matrix3.h"




class Game
{
public:
	Game();
	~Game();
	void run();
	std::string loadShader(const std::string& fileName);
	

	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	
	Vector3 m_cubePoints[8];

	void transformCube(Matrix3 &);
	void translatePoints(double translation, const Matrix3::Axis &axis);
	void moveCentrePoint(double, const Matrix3::Axis&);
	float inverse(float);
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;
	Vector3 m_centrePoint = Vector3(0,0,0);
	float rotationAngle = 0.0f;
};

#endif