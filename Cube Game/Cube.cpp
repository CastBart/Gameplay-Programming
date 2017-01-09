#include "Cube.h"


typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[8];
GLubyte triangles[36];

Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::initialize()
{
	vertex[0].coordinate[0] = -1.0f;	//bottom left f 0
	vertex[0].coordinate[1] = -1.0f;
	vertex[0].coordinate[2] = 1.0f;

	vertex[1].coordinate[0] = -1.0f;	//top left f   1
	vertex[1].coordinate[1] = 1.0f;
	vertex[1].coordinate[2] = 1.0f;

	vertex[2].coordinate[0] = 1.0f;		//top right f   2
	vertex[2].coordinate[1] = 1.0f;
	vertex[2].coordinate[2] = 1.0f;

	vertex[3].coordinate[0] = 1.0f;		//bottom right f 3
	vertex[3].coordinate[1] = -1.0f;
	vertex[3].coordinate[2] = 1.0f;


	vertex[4].coordinate[0] = -1.0f;	//bottom left b 4
	vertex[4].coordinate[1] = -1.0f;
	vertex[4].coordinate[2] = -1.0f;

	vertex[5].coordinate[0] = -1.0f;	//top left b   5
	vertex[5].coordinate[1] = 1.0f;
	vertex[5].coordinate[2] = -1.0f;

	vertex[6].coordinate[0] = 1.0f;		//top right b  6
	vertex[6].coordinate[1] = 1.0f;
	vertex[6].coordinate[2] = -1.0f;

	vertex[7].coordinate[0] = 1.0f;		//bottom right b 7
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



	triangles[30] = 0;   triangles[31] = 1;   triangles[32] = 2;//012
	triangles[33] = 2;   triangles[34] = 3;   triangles[35] = 0;//230

	triangles[6] = 0;   triangles[7] = 1;   triangles[8] = 5;
	triangles[9] = 5;   triangles[10] = 4;   triangles[11] = 0;

	triangles[12] = 3;   triangles[13] = 2;   triangles[14] = 6;
	triangles[15] = 6;   triangles[16] = 7;   triangles[17] = 3;

	triangles[18] = 5;   triangles[19] = 1;   triangles[20] = 2;
	triangles[21] = 2;   triangles[22] = 6;   triangles[23] = 5;

	triangles[24] = 3;   triangles[25] = 0;   triangles[26] = 4;
	triangles[27] = 3;   triangles[28] = 7;   triangles[29] = 4;

	triangles[0] = 7;   triangles[1] = 6;   triangles[2] = 5; //back face
	triangles[3] = 5;   triangles[4] = 4;   triangles[5] = 7;
}

void Cube::transformCube(Matrix3 &)
{
}

void Cube::translatePoints(double translation, const Matrix3::Axis & axis)
{
}

void Cube::update()
{
}

void Cube::render()
{
}

void Cube::unload()
{
}
