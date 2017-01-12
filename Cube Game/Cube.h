#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3.h"
#include "Matrix3.h"
#include <memory>

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;


class Cube
{
public:
	
	Cube(float offset = 0);
	~Cube();
	void render();
	void unload();
	void initialize();
	void transformCube(Matrix3 &);
	void translatePoints(double translation, const Matrix3::Axis &axis);

	void update();

private:
	

	Vertex vertex[8];
	GLubyte triangles[36];
	
	
	Vector3 m_cubePoints[8];
	
	GLuint index;

	float m_offset;
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;

};

