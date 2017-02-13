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
	void render(ProgramIds& ids, glm::mat4& mpv);
	void unload();
	void initialize(ProgramIds & ids);

	void transformCube(Matrix3 &);
	void translatePoints(double translation, const Matrix3::Axis &axis);
	void moveCentrePoint(double, const Matrix3::Axis&);
	float inverse(float);

	void update(double dt);

	GLuint index;

	Vertex vertex[8];
	GLubyte triangles[36];

	GLfloat uvs[2 * 4 * 6] = {
		// Front Face (other faces populated in initialisation)
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0
	};

	Vector3 m_cubePoints[8];

	float m_offset;
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;

	Vector3 m_centrePoint;

	const int VERTICES = 24;	// Total Number of Vertices
	const int INDICES = 12;	// Total Number of Indexes
	const int UVS = 48;	// Total Number of UVs
	const int COLORS = 24;	// Total Number of Colors

};


	

	

	
	

#endif

