#include "Cube.h"


const GLfloat Cube::vertices[] =
{
	// Front Face
	-1.00f, -1.00f,  1.00f,	// [0]	// ( 0)
	1.00f, -1.00f,  1.00f,	// [1]	// ( 1)
	1.00f,  1.00f,  1.00f,	// [2]	// ( 2)
	-1.00f,  1.00f,  1.00f,	// [3]	// ( 3)

	// Top Face
	-1.00f,  1.00f,  1.00f,	// [3]	// ( 4)
	1.00f,  1.00f,  1.00f,	// [2]	// ( 5)
	1.00f,  1.00f, -1.00f,	// [6]	// ( 6)
	-1.00f,  1.00f, -1.00f,	// [7]	// ( 7)

							// Back Face
	1.00f, -1.00f, -1.00f,	// [5]	// ( 8)
	-1.00f, -1.00f, -1.00f, // [4]	// ( 9)
	-1.00f,  1.00f, -1.00f,	// [7]	// (10)
	1.00f,  1.00f, -1.00f,	// [6]	// (11)

	// Bottom Face
	-1.00f, -1.00f, -1.00f, // [4]	// (12)
	1.00f, -1.00f, -1.00f, // [5]	// (13)
	1.00f, -1.00f,  1.00f, // [1]	// (14)
	-1.00f, -1.00f,  1.00f, // [0]	// (15)

	// Left Face
	-1.00f, -1.00f, -1.00f, // [4]	// (16)
	-1.00f, -1.00f,  1.00f, // [0]	// (17)
	-1.00f,  1.00f,  1.00f, // [3]	// (18)
	-1.00f,  1.00f, -1.00f, // [7]	// (19)

	// Right Face
	1.00f, -1.00f,  1.00f, // [1]	// (20)
	1.00f, -1.00f, -1.00f, // [5]	// (21)
	1.00f,  1.00f, -1.00f, // [6]	// (22)
	1.00f,  1.00f,  1.00f, // [2]	// (23)
};

const GLfloat Cube::colors[] = {

	// Front Face
	1.0f, 0.0f, 0.0f, 1.0f, // [0]	// ( 0)
	1.0f, 0.0f, 0.0f, 1.0f, // [1]	// ( 1)
	1.0f, 0.0f, 0.0f, 1.0f, // [2]	// ( 2)
	1.0f, 0.0f, 0.0f, 1.0f, // [3]	// ( 3)

	// Top Face
	0.0f, 1.0f, 0.0f, 1.0f, // [3]	// ( 4)
	0.0f, 1.0f, 0.0f, 1.0f, // [2]	// ( 5)
	0.0f, 1.0f, 0.0f, 1.0f, // [6]	// ( 6)
	0.0f, 1.0f, 0.0f, 1.0f, // [7]	// ( 7)

							// Back Face
	0.0f, 0.0f, 1.0f, 1.0f, // [5]	// ( 8)
	0.0f, 0.0f, 1.0f, 1.0f, // [4]	// ( 9)
	0.0f, 0.0f, 1.0f, 1.0f, // [7]	// (10)
	0.0f, 0.0f, 1.0f, 1.0f, // [6]	// (11)

							// Bottom Face
	0.0f, 1.0f, 1.0f, 1.0f, // [4]	// (12)
	0.0f, 1.0f, 1.0f, 1.0f, // [5]	// (13)
	0.0f, 1.0f, 1.0f, 1.0f, // [1]	// (14)
	0.0f, 1.0f, 1.0f, 1.0f, // [0]	// (15)

							// Left Face
	1.0f, 1.0f, 0.0f, 1.0f, // [4]	// (16)
	1.0f, 1.0f, 0.0f, 1.0f, // [0]	// (17)
	1.0f, 1.0f, 0.0f, 1.0f, // [3]	// (18)
	1.0f, 1.0f, 0.0f, 1.0f, // [7]	// (19)

	// Right Face
	1.0f, 0.0f, 1.0f, 1.0f, // [1]	// (20)
	1.0f, 0.0f, 1.0f, 1.0f, // [5]	// (21)
	1.0f, 0.0f, 1.0f, 1.0f, // [6]	// (22)
	1.0f, 0.0f, 1.0f, 1.0f, // [2]	// (23)
};

GLfloat uvs[2 * 4 * 6] = {
	// Front Face (other faces populated in initialisation)
	//top right coordinates
	3.0f / 3.0f , 1.0f / 3.0f,
	2.0f / 3.0f, 1.0f / 3.0f,
	2.0f / 3.0f, 0.0f / 3.0f,
	3.0f / 3.0f, 0.0f / 3.0f,
	
	
	//top face       bottm right
	3.0f / 3.0f, 3.0f / 3.0f,
	2.0f / 3.0f, 3.0f / 3.0f,
	2.0f / 3.0f, 2.0f / 3.0f,
	3.0f / 3.0f ,2.0f / 3.0f,

	//back face		top centre
	2.0f / 3.0f, 1.0f / 3.0f,
	1.0f / 3.0f, 1.0f / 3.0f,
	1.0f / 3.0f, 0.0f / 3.0f,
	2.0f / 3.0f, 0.0f / 3.0f,

	//bottom face    right centre
	3.0f / 3.0f , 2.0f / 3.0f,
	2.0f / 3.0f, 2.0f / 3.0f,
	2.0f / 3.0f, 1.0f / 3.0f,
	3.0f / 3.0f, 1.0f / 3.0f,


	//left face		left centre
	1.0f / 3.0f , 2.0f / 3.0f,
	0.0f / 3.0f, 2.0f / 3.0f,
	0.0f / 3.0f, 1.0f / 3.0f,
	1.0f / 3.0f, 1.0f / 3.0f,

	//right face    bottom centre
	2.0f / 3.0f , 3.0f / 3.0f,
	1.0f / 3.0f, 3.0f / 3.0f,
	1.0f / 3.0f, 2.0f / 3.0f,
	2.0f / 3.0f, 2.0f / 3.0f,
};

const GLuint Cube::indices[] =
{
	// Front Face
	0, 1, 2,
	2, 3, 0,

	// Top Face
	4, 5, 6,
	6, 7, 4,

	// Back Face
	8, 9, 10,
	10, 11, 8,

	// Bottom Face
	12, 13, 14,
	14, 15, 12,

	// Left Face
	16, 17, 18,
	18, 19, 16,

	// Right Face
	20, 21, 22,
	22, 23, 20
};


Cube::Cube(float offset) :
	m_offset(offset),
	m_centrePoint(offset, 0, 0)
	//matrix(Matrix3::Scale(0.99f, 0.99f, 0.99f))
{
}


Cube::~Cube()
{
}

void Cube::render(ProgramIds & ids, glm::mat4& mvp)
{

	glBindBuffer(GL_ARRAY_BUFFER, ids.vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ids.vib);

	glUseProgram(ids.progID);

	glBufferSubData(GL_ARRAY_BUFFER, 0 * VERTICES * sizeof(GLfloat), 3 * VERTICES * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, 3 * VERTICES * sizeof(GLfloat), 4 * COLORS * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat), 2 * UVS * sizeof(GLfloat), uvs);

	// Send transformation to shader mvp uniform
	glUniformMatrix4fv(ids.mvpID, 1, GL_FALSE, &mvp[0][0]);

	//Set Active Texture .... 32
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(ids.textureID, 0);

	////Set pointers for each parameter (with appropriate starting positions)
	////https://www.khronos.org/opengles/sdk/docs/man/xhtml/glVertexAttribPointer.xml
	glVertexAttribPointer(ids.positionID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glVertexAttribPointer(ids.colorID, 4, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<const void*>(3 * VERTICES * sizeof(GLfloat)));
	glVertexAttribPointer(ids.uvID, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<const void*>(((3 * VERTICES) + ( 4 * COLORS)) * sizeof(GLfloat)));

	//Enable Arrays
	glEnableVertexAttribArray(ids.positionID);
	glEnableVertexAttribArray(ids.colorID);
	glEnableVertexAttribArray(ids.uvID);

	glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, nullptr);


	//Disable Arrays
	glDisableVertexAttribArray(ids.positionID);
	glDisableVertexAttribArray(ids.colorID);
	glDisableVertexAttribArray(ids.uvID);

}

void Cube::initialize(ProgramIds & ids)
{
	//vertex[0].coordinate[0] = -1.0f + m_offset;	//bottom left f 0
	//vertex[0].coordinate[1] = -1.0f;
	//vertex[0].coordinate[2] = 1.0f;

	//vertex[1].coordinate[0] = -1.0f + m_offset;	//top left f   1
	//vertex[1].coordinate[1] = 1.0f;
	//vertex[1].coordinate[2] = 1.0f;

	//vertex[2].coordinate[0] = 1.0f + m_offset;		//top right f   2
	//vertex[2].coordinate[1] = 1.0f;
	//vertex[2].coordinate[2] = 1.0f;

	//vertex[3].coordinate[0] = 1.0f + m_offset;		//bottom right f 3    
	//vertex[3].coordinate[1] = -1.0f;
	//vertex[3].coordinate[2] = 1.0f;


	//vertex[4].coordinate[0] = -1.0f + m_offset;	//bottom left b 4      
	//vertex[4].coordinate[1] = -1.0f;
	//vertex[4].coordinate[2] = -1.0f;

	//vertex[5].coordinate[0] = -1.0f + m_offset;	//top left b   5
	//vertex[5].coordinate[1] = 1.0f;
	//vertex[5].coordinate[2] = -1.0f;

	//vertex[6].coordinate[0] = 1.0f + m_offset;		//top right b  6
	//vertex[6].coordinate[1] = 1.0f;
	//vertex[6].coordinate[2] = -1.0f;

	//vertex[7].coordinate[0] = 1.0f + m_offset;		//bottom right b 7
	//vertex[7].coordinate[1] = -1.0f;
	//vertex[7].coordinate[2] = -1.0f;


	//vertex[0].color[0] = 0.0f;
	//vertex[0].color[1] = 1.0f;
	//vertex[0].color[2] = 0.0f;
	//vertex[0].color[3] = 1.0f;

	//vertex[1].color[0] = 0.5f;
	//vertex[1].color[1] = 0.5f;
	//vertex[1].color[2] = 0.0f;
	//vertex[1].color[3] = 1.0f;

	//vertex[2].color[0] = 1.0f;
	//vertex[2].color[1] = 0.0f;
	//vertex[2].color[2] = 0.0f;
	//vertex[2].color[3] = 1.0f;

	//vertex[3].color[0] = 1.0f;
	//vertex[3].color[1] = 0.0f;
	//vertex[3].color[2] = 1.0f;
	//vertex[3].color[3] = 1.0f;

	//vertex[4].color[0] = 0.0f;
	//vertex[4].color[1] = 1.0f;
	//vertex[4].color[2] = 0.0f;
	//vertex[4].color[3] = 1.0f;

	//vertex[5].color[0] = 0.5f;
	//vertex[5].color[1] = 0.5f;
	//vertex[5].color[2] = 0.0f;
	//vertex[5].color[3] = 1.0f;

	//vertex[6].color[0] = 1.0f;
	//vertex[6].color[1] = 0.0f;
	//vertex[6].color[2] = 0.0f;
	//vertex[6].color[3] = 1.0f;

	//vertex[7].color[0] = 1.0f;
	//vertex[7].color[1] = 0.0f;
	//vertex[7].color[2] = 1.0f;
	//vertex[7].color[3] = 1.0f;



	//triangles[30] = 1;   triangles[31] = 0;   triangles[32] = 3;  // front
	//triangles[33] = 2;   triangles[34] = 1;   triangles[35] = 3;

	//triangles[6] = 0;   triangles[7] = 1;   triangles[8] = 5;     //left side
	//triangles[9] = 5;   triangles[10] = 4;   triangles[11] = 0;

	//triangles[12] = 2;   triangles[13] = 3;   triangles[14] = 7; // right side
	//triangles[15] = 6;   triangles[16] = 2;   triangles[17] = 7;

	//triangles[18] = 5;   triangles[19] = 1;   triangles[20] = 2; // top face
	//triangles[21] = 6;   triangles[22] = 5;   triangles[23] = 2;

	//triangles[24] = 0;   triangles[25] = 4;   triangles[26] = 7;
	//triangles[27] = 3;   triangles[28] = 0;   triangles[29] = 7;

	//triangles[0] = 4;   triangles[1] = 5;   triangles[2] = 6; //back face
	//triangles[3] = 7;   triangles[4] = 4;   triangles[5] = 6;


	
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//Vertices 3 x,y,z , Colors 4 RGBA, UV/ST 2
	/*glBufferData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS) + (2 * UVS)) * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);*/


	


}

