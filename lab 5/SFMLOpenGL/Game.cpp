#pragma once
#include "Game.h"


bool flip = false;
int current = 1;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL"), primatives(2)
{
	index = glGenLists(primatives);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;
	
	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					rotateUsingMatrix();
					break;
				case sf::Keyboard::Down:
					rotateUsingQuaternion();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		update(event);
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	point1 = Vector3(0.2, 0.0, -10.0);
	point2 = Vector3(-2.0, -2.0, -10.0);
	point3 = Vector3(2.0, -2.0, -10.0);

	point4 = Vector3(0.0, 2.0, -10.0);
	point5 = Vector3(-2.0, -2.0, -10.0);
	point6 = Vector3(2.0, -2.0, -10.0);
	

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	//glNewList(index, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(point4.M_X(), point4.M_Y(), point4.M_Z());
	//	glVertex3f(point5.M_X(), point5.M_Y(), point5.M_Z());
	//	glVertex3f(point6.M_X(), point6.M_Y(), point6.M_Z());
	//}
	//glEnd();
	//glEndList();

	//glNewList(index + 1, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	
	//	glVertex3f(point1.M_X(), point1.M_Y(), point1.M_Z());
	//	glVertex3f(point2.M_X(), point2.M_Y(), point2.M_Z());
	//	glVertex3f(point3.M_X(), point3.M_Y(), point3.M_Z());
	//}
	//glEnd();
	//glEndList();
	
	
}

void Game::update(sf::Event &event)
{
	elapsed = clock.sf::Clock::getElapsedTime();
	
	Matrix3 m1();
	
	if (elapsed.sf::Time::asSeconds() >= 1.0f)
	{
		clock.sf::Clock::restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	
	
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	
	
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(point4.M_X(), point4.M_Y(), point4.M_Z());
		glVertex3f(point5.M_X(), point5.M_Y(), point5.M_Z());
		glVertex3f(point6.M_X(), point6.M_Y(), point6.M_Z());
	}
	glEnd();
	glEndList();


	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);

		glVertex3f(point1.M_X(), point1.M_Y(), point1.M_Z());
		glVertex3f(point2.M_X(), point2.M_Y(), point2.M_Z());
		glVertex3f(point3.M_X(), point3.M_Y(), point3.M_Z());
	}
	glEnd();
	glEndList();

	
	cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::rotateUsingMatrix()
{
	matrix = Matrix3::Rotation(3, Matrix3::Axis::Z);
	point1 = matrix*point1;
	point2 = matrix*point2;
	point3 = matrix*point3;
}

void Game::rotateUsingQuaternion()
{
	quaternion = Quaternion(0, 0, 0, 1);
	point4 = quaternion.Rotate(point4, 10);
	point5 = quaternion.Rotate(point5, 10);
	point6 = quaternion.Rotate(point6, 10);
}

