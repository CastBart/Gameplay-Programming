#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"
#include "Quaternion.h"


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
	void update(sf::Event &);
	void draw();
	void unload();
	const int primatives;
	void rotateUsingMatrix();
	void rotateUsingQuaternion();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;
	Vector3 point1;
	Vector3 point2;
	Vector3 point3;
	Matrix3 matrix;

	Vector3 point4;
	Vector3 point5;
	Vector3 point6;
	Quaternion quaternion;
	float rotationAngle = 0.0f;
};