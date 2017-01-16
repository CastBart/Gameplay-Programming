#pragma once
#include "Game.h"

static bool flip;
static double const MS_PER_UPDATE = 10.0;

Game::Game(sf::ContextSettings settings) : window(sf::VideoMode(800, 600), "OpenGL Cube VBO", sf::Style::Default, settings)
{
	
}

Game::~Game() {}


void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	initialize();

	sf::Event event;

	while (isRunning) 
	{

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}

//Key States
#pragma region
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					//rotates ABOUT the x axis
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::X);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Down:
					//rotates ABOUT the x axis
					matrix = Matrix3::Rotation(1, Matrix3::Axis::X);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Left:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Y);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Right:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Y);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Comma:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Z);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Period:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Z);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Add:
					matrix = Matrix3::Scale(1.1, 1.1, 1.1);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::Subtract:
					matrix = Matrix3::Scale(0.9, 0.9, 0.9);
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].transformCube(matrix);
					}
					
					break;
				case sf::Keyboard::D:
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].translatePoints(1, Matrix3::Axis::Z);
					}
					
					break;
				case sf::Keyboard::A:
					for (int i = 0; i < 6; i++)
					{
						m_cube[i].translatePoints(-1, Matrix3::Axis::Z);
					}
					
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
#pragma endregion
		}
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		render();
	}

}





void Game::initialize()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);



	isRunning = true;
	glewInit();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);
	
	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	
	for (int i = 0; i < 6; i++)
	{
		m_cube[i].initialize();
	}
	
	
}

void Game::update(double dt)
{
	glCullFace(GL_BACK);
	for (int i = 0; i < 6; i++)
	{
		m_cube[i].update(dt);
	}
}

void Game::render()
{

	glEnable(GL_STENCIL_TEST);
	cout << "Drawing" << endl;
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -30.0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	for (int i = 0; i < 6; i++)
	{
		m_cube[i].render();
	}
	
	


	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
	glDeleteBuffers(1, vbo);
}


