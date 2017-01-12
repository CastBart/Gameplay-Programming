#pragma once
#include "Game.h"

static bool flip;
 

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube VBO")
{
	
}

Game::~Game() {}


void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

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
					//rotates ABOUT the x axis
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::X);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Down:
					//rotates ABOUT the x axis
					matrix = Matrix3::Rotation(1, Matrix3::Axis::X);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Left:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Y);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Right:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Y);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Comma:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Z);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Period:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Z);
					m_cube.transformCube(matrix);
					break;
				case sf::Keyboard::Add:
					matrix = Matrix3::Scale(1.1, 1.1, 1.1);
					m_cube2.transformCube(matrix);
					break;
				case sf::Keyboard::Subtract:
					matrix = Matrix3::Scale(0.9, 0.9, 0.9);
					m_cube2.transformCube(matrix);
					break;
				case sf::Keyboard::D:
					m_cube.translatePoints(1, Matrix3::Axis::Z);
					break;
				case sf::Keyboard::A:
					m_cube.translatePoints(-1, Matrix3::Axis::Z);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		update();
		render();
	}

}





void Game::initialize()
{

	//glEnable(GL_CULL_VERTEX_EXT);
	/*glEnable(GL_CULL_VERTEX_OBJECT_POSITION_EXT);*/

	glEnable(GL_CULL_FACE);

	//glEnable(GL_DEPTH_TEST);

	isRunning = true;
	glewInit();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	/* Vertices counter-clockwise winding */



	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);
	

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);


	m_cube.initialize();
	m_cube2.initialize();
}

void Game::update()
{
	
	glCullFace(GL_BACK);
		
	elapsed = clock.getElapsedTime();
	//glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex), triangles, GL_DYNAMIC_DRAW);
	/*if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}*/
	
	/*if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}*/

	
}

void Game::render()
{

	glEnable(GL_STENCIL_TEST);
	cout << "Drawing" << endl;
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -15.0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	m_cube.render();
	m_cube2.render();


	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
	glDeleteBuffers(1, vbo);
}


