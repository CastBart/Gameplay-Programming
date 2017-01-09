#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3.h"
#include "Matrix3.h"
class Cube
{
public:
	Cube();
	~Cube();

private:
	sf::Window window;
	void initialize();
	void transformCube(Matrix3 &);
	void translatePoints(double translation, const Matrix3::Axis &axis);

	void update();
	void render();
	void unload();
	Vector3 m_cubePoints[8];

	

	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;

};

