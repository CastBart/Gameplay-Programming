#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "Matrix3.h"

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
	void draw();
	void unload();
	void rotatePoint(double angle, Matrix3::Axis axis);
	void translatePoints();
	void scalePoints();
	const int primitives;

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;
	Vector3 m_cubePoints[8];
	Matrix3 rotationMatrix;
	float rotationAngle = 0.0f;
};