#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3.h"
#include "Matrix3.h"
#include <memory>
#include <time.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ProgramIds.h"

//Cube Vertices
/*
		  (-1.0f, 1.0f, -1.0f)          (1.0f, 1.0f, -1.0f)
		          [7]                          [6]
		          #-----------------------------#
		         /|                            /|
		        / |                           / |
	  (-1.0f, 1.0f, 1.0f)           (1.0f, 1.0f, 1.0f)
		  [3] /                         [2] /
		     #-----------------------------#    |
		     |    |                        |    |
		     |    |                        |    |
		     |   [4]                       |   [5]
		  (-1.0f, -1.0f, -1.0f)         (1.0f, -1.0f, -1.0f)
		     |    #-----------------------------#
		     |   /                         |   /
		     |  /                          |  /
		     | /                           | /
		     |/                            |/
		     #-----------------------------#
		    [0]                           [1]
	(-1.0f, -1.0f, 1.0f)         (1.0f, -1.0f, 1.0f)
*/

//typedef struct
//{
//	float coordinate[3];
//	float color[4];
//	//float uvs[2];
//
//} Vertex;
const int VERTICES = 24;	// Total Number of Vertices
const int INDICES = 12;	// Total Number of Indexes
const int UVS = 48;	// Total Number of UVs
const int COLORS = 24;	// Total Number of Colors


class Cube
{
public:
	Cube();
	Cube(bool player);

	~Cube();
	void render(ProgramIds& ids, glm::mat4& mpv);
	//void unload();
	void initialize();
	void update();

	static const GLuint indices[];
	static GLfloat vertices[];
	static const GLfloat colors[];
	

	Vector3 m_cubePoints[24];

	float m_offset;
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;

	Vector3 m_centrePoint;

	glm::mat4 view, model, projection, mvp;
	bool m_isPlayer;
	
};


	

	

	
	

#endif

