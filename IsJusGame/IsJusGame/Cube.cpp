#include "Cube.h"


GLfloat Cube::vertices[] =
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

Cube::Cube(const glm::mat4& camera)
	: view(camera)
{

}

Cube::Cube(const glm::mat4& camera, bool player, int offsetZ) :
	m_isPlayer(player)
	, view(camera)
	, m_offsetZ(offsetZ)
{
	srand(time(NULL));
	
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

void Cube::initialize()
{
	projection = glm::perspective(
		45.0f,					// Field of View 45 degrees
		4.0f / 3.0f,			// Aspect ratio
		5.0f,					// Display Range Min : 0.1f unit
		100.0f					// Display Range Max : 100.0f unit
	);

	model = glm::mat4(
		1.0f					// Identity Matrix
	);

	if (!m_isPlayer)
	{
		int randomX;
		int randomY;

		randomX = rand() % 20 - 10;
		randomY = rand() % 20 - 10;

		std::cout << randomY << std::endl;
		std::cout << randomX << std::endl;
		model = glm::translate(model, glm::vec3(randomX, randomY, m_offsetZ));
	}
}


void Cube::update( double dt)
{
	mvp = projection * view * model;
	if (!m_isPlayer)
	{
		model = glm::translate(model, glm::vec3(0, 0, 0.03));
	}
}

void Cube::setRandomPos()
{
	if (!m_isPlayer)
	{

		int randomX;
		int randomY;

		randomX = rand() % 20 - 10;
		randomY = rand() % 20 - 10;

		std::cout << randomY << std::endl;
		std::cout << randomX << std::endl;
		model = glm::translate(model, glm::vec3(randomX, randomY, m_offsetZ));


	}
}



