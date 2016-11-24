#include "Game.h"


Game::Game(ContextSettings settings) : 
	window(VideoMode(800u, 600u), "OpenGL", Style::Close, settings)
{
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawTriangle();
	drawPoint();
	drawLine();
	drawLineStrip();
	drawLineLoop();
	drawTriangleStrip();
	drawTriangleFan();
	drawQuad();
	drawQuadStrip();
	drawPolygon();
	
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::drawTriangle()
{
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1, 1.5, -5.0);
		glVertex3f(0.5, 0.35, -5.0);
		glVertex3f(1.5, 0.35, -5.0);
	}
	glEnd();
}

void Game::drawPoint()
{
	glPointSize(20.0);
	glBegin(GL_POINTS);
	{
		glColor3f(1.0, 0, 0);
		glVertex3d(0.3, 0.2, -1.0);
	}
	glEnd();
}

void Game::drawLine()
{
	
	glBegin(GL_LINES);
	{
		glColor3f(0.0, 1.0, 1.0);
		glVertex3d(0.0, 0.4, -1.0);
		glVertex3d(0.0, 0.1, -1.0);
	}
	glEnd();
}

void Game::drawLineStrip()
{
	
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(0.0, 1.0, 0.0);
		glVertex3d(-0.1, 0.4, -1.0);
		glVertex3d(-0.1, 0.1, -1.0);
		glVertex3d(-0.2, 0.1, -1.0);
	}
	glEnd();
}

void Game::drawLineLoop()
{
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0, 1.0, 0.0);
		glVertex3d(-0.25, 0.2, -1.0);
		glVertex3d(-0.25, 0.1, -1.0);
		glVertex3d(-0.3, 0.1, -1.0);
	}
	glEnd();
}

void Game::drawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3d(-0.25, 0.0, -1.0);
		glVertex3d(-0.25, -0.1, -1.0);
		glVertex3d(-0.3, -0.1, -1.0);
		glVertex3d(-0.3, -0.05, -1.0);
	}
	glEnd();
}

void Game::drawTriangleFan()
{
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3d(-0.1, 0.0, -1.0);
		glVertex3d(-0.15, -0.05, -1.0);
		glVertex3d(-0.2, 0.0, -1.0);
		glVertex3d(-0.15, 0.05, -1.0);
		
	}
	glEnd();
}

void Game::drawQuad()
{
	glBegin(GL_QUADS);
	{
		glVertex3d(0.1, 0.0, -1.0);
		glVertex3d(0.05, -0.1, -1.0);
		glVertex3d(0.0, 0.0, -1.0);
		glVertex3d(0.05, 0.05, -1.0);
	}
	glEnd();
}

void Game::drawQuadStrip()
{
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3d(0.25, 0.0, -1.0);
		glVertex3d(0.2, -0.1, -1.0);
		glVertex3d(0.2, 0.05, -1.0);
		glVertex3d(0.15, 0.0, -1.0);
		glVertex3d(0.25, 0.05, -1.0);
		glVertex3d(0.3, 0.0, -1.0);
	}
	glEnd();
}

void Game::drawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.25, -0.15, -1.0);//0
		glVertex3d(-0.25, -0.1, -1.0);//-1
		glVertex3d(-0.2, -0.05, -1.0);//0
		glVertex3d(-0.15, -0.1, -1.0);//-1.5
		glVertex3d(-0.15, -0.15, -1.0);//-1.5
		glVertex3d(-0.2, -0.2, -1.0);//0
	}
	glEnd();
}

