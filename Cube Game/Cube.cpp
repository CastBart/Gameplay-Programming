#pragma once
#include "Cube.h"


Cube::Cube(float offset):
	m_offset(offset),
	m_centrePoint(offset,0,0),
	matrix(Matrix3::Scale(0.99f, 0.99f, 0.99f))
{
}


Cube::~Cube()
{
}

void Cube::initialize()
{
	vertex[0].coordinate[0] = -1.0f + m_offset;	//bottom left f 0
	vertex[0].coordinate[1] = -1.0f;
	vertex[0].coordinate[2] = 1.0f;

	vertex[1].coordinate[0] = -1.0f + m_offset;	//top left f   1
	vertex[1].coordinate[1] = 1.0f;
	vertex[1].coordinate[2] = 1.0f;

	vertex[2].coordinate[0] = 1.0f + m_offset;		//top right f   2
	vertex[2].coordinate[1] = 1.0f;
	vertex[2].coordinate[2] = 1.0f;

	vertex[3].coordinate[0] = 1.0f + m_offset;		//bottom right f 3    
	vertex[3].coordinate[1] = -1.0f;
	vertex[3].coordinate[2] = 1.0f;


	vertex[4].coordinate[0] = -1.0f + m_offset;	//bottom left b 4      
	vertex[4].coordinate[1] = -1.0f;
	vertex[4].coordinate[2] = -1.0f;

	vertex[5].coordinate[0] = -1.0f + m_offset;	//top left b   5
	vertex[5].coordinate[1] = 1.0f;
	vertex[5].coordinate[2] = -1.0f;

	vertex[6].coordinate[0] = 1.0f + m_offset;		//top right b  6
	vertex[6].coordinate[1] = 1.0f;
	vertex[6].coordinate[2] = -1.0f;

	vertex[7].coordinate[0] = 1.0f + m_offset;		//bottom right b 7
	vertex[7].coordinate[1] = -1.0f;
	vertex[7].coordinate[2] = -1.0f;


	vertex[0].color[0] = 0.0f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.5f;
	vertex[1].color[1] = 0.5f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 1.0f;
	vertex[2].color[1] = 0.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 1.0f;
	vertex[3].color[1] = 0.0f;
	vertex[3].color[2] = 1.0f;

	vertex[4].color[0] = 0.0f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.5f;
	vertex[5].color[1] = 0.5f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 1.0f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 1.0f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;



	triangles[30] = 1;   triangles[31] = 0;   triangles[32] = 3;  // front
	triangles[33] = 2;   triangles[34] = 1;   triangles[35] = 3;

	triangles[6] = 0;   triangles[7] = 1;   triangles[8] = 5;     //left side
	triangles[9] = 5;   triangles[10] = 4;   triangles[11] = 0;

	triangles[12] = 2;   triangles[13] = 3;   triangles[14] = 7; // right side
	triangles[15] = 6;   triangles[16] = 2;   triangles[17] = 7;

	triangles[18] = 5;   triangles[19] = 1;   triangles[20] = 2; // top face
	triangles[21] = 6;   triangles[22] = 5;   triangles[23] = 2;

	triangles[24] = 0;   triangles[25] = 4;   triangles[26] = 7;
	triangles[27] = 3;   triangles[28] = 0;   triangles[29] = 7;

	triangles[0] = 4;   triangles[1] = 5;   triangles[2] = 6; //back face
	triangles[3] = 7;   triangles[4] = 4;   triangles[5] = 6;

	
	
	
	
	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 8, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::transformCube(Matrix3 &matrix)
{
	for (int i = 0; i < 8; i++)
	{

		m_cubePoints[i] = Vector3(vertex[i].coordinate[0] , vertex[i].coordinate[1], vertex[i].coordinate[2]);
		m_cubePoints[i] = Vector3( (m_cubePoints[i].M_X() + inverse(m_centrePoint.M_X())) , (m_cubePoints[i].M_Y() + inverse(m_centrePoint.M_Y())),(m_cubePoints[i].M_Z() + inverse(m_centrePoint.M_Z())));
		
		
		m_cubePoints[i] = matrix * m_cubePoints[i];

		m_cubePoints[i] = Vector3(m_cubePoints[i].M_X() + m_centrePoint.M_X(), m_cubePoints[i].M_Y() + m_centrePoint.M_Y(), m_cubePoints[i].M_Z() + m_centrePoint.M_Z());

		vertex[i].coordinate[0] = m_cubePoints[i].M_X();
		vertex[i].coordinate[1] = m_cubePoints[i].M_Y();
		vertex[i].coordinate[2] = m_cubePoints[i].M_Z();
	}
}

void Cube::translatePoints(double translation, const Matrix3::Axis & axis)
{
	moveCentrePoint(translation, axis);
	for (int i = 0; i < 8; i++)
	{
		m_cubePoints[i] = Vector3(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);
		m_cubePoints[i] = Matrix3::translate(m_cubePoints[i], translation, axis);
		vertex[i].coordinate[0] = m_cubePoints[i].M_X();
		vertex[i].coordinate[1] = m_cubePoints[i].M_Y();
		vertex[i].coordinate[2] = m_cubePoints[i].M_Z();
	}
}

void Cube::moveCentrePoint(double translation, const Matrix3::Axis& axis)
{

	switch (axis)
	{
	case Matrix3::Axis::X:
		m_centrePoint = Vector3(m_centrePoint.M_X() + translation, m_centrePoint.M_Y(), m_centrePoint.M_Z());
		break;
	case Matrix3::Axis::Y:
		m_centrePoint = Vector3(m_centrePoint.M_X(), m_centrePoint.M_Y() + translation, m_centrePoint.M_Z());

		break;
	case Matrix3::Axis::Z:
		m_centrePoint = Vector3(m_centrePoint.M_X(), m_centrePoint.M_Y(), m_centrePoint.M_Z() + translation);

		break;
	default:
		m_centrePoint = Vector3(m_centrePoint.M_X(), m_centrePoint.M_Y(), m_centrePoint.M_Z());
		break;
	}

}

float Cube::inverse(float number)
{
	if (number < 0)
	{
		number = -number;
	}
	else if( number > 0)
	{
		number =  -number;
	}
	return number;
}

void Cube::update(double dt)
{
	translatePoints(0.1f, Matrix3::Axis::Z);
	transformCube(matrix);

}

void Cube::render()
{
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 8, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/* Draw Triangle from VBO */

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	
}

void Cube::unload()
{
}
