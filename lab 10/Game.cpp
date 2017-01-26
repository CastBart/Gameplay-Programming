#include <Game.h>

static bool flip;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube Vertex and Fragment Shaders")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

#if (DEBUG >= 2)
		DEBUG_MSG("Game running...");
#endif

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
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Down:
					//rotates ABOUT the x axis
					matrix = Matrix3::Rotation(1, Matrix3::Axis::X);
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Left:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Y);
					
					transformCube(matrix);
					

					break;
				case sf::Keyboard::Right:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Y);
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Comma:
					matrix = Matrix3::Rotation(1, Matrix3::Axis::Z);
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Period:
					matrix = Matrix3::Rotation(-1, Matrix3::Axis::Z);
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Add:
					matrix = Matrix3::Scale(1.1, 1.1, 1.1);
					
						transformCube(matrix);
					

					break;
				case sf::Keyboard::Subtract:
					matrix = Matrix3::Scale(0.9, 0.9, 0.9);
					transformCube(matrix);
					break;
				case sf::Keyboard::D:
					translatePoints(0.1, Matrix3::Axis::X);
					break;
				case sf::Keyboard::A:
					translatePoints(-0.1, Matrix3::Axis::X);
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

std::string Game::loadShader(const std::string & fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	
	while (!file.eof())
	{
		getline(file, line);
		output.append(line + "\n");
	}
	
	
	return output;
	
}


typedef struct
{
	float coordinate[3];
	float color[4];
	float texel[2];
} Vertex;

Vertex vertex[8];
GLubyte triangles[36];

/* Variable to hold the VBO identifier and shader data */
GLuint	index, //Index to draw
vsid, //Vertex Shader ID
fsid, //Fragment Shader ID
progID, //Program ID
vao = 0, //Vertex Array ID
vbo[1], // Vertex Buffer ID
positionID, //Position ID
colorID, // Color ID
to,
textureID,
texelID;



const std::string filename = "texture.tga";

int width; //width of texture
int height; //height of texture
int comp_count; //Component of texture
const int number = 4; //4 = RGBA

unsigned char* img_data;


void Game::initialize()
{
	

	isRunning = true;
	GLint isCompiled = 0;
	GLint isLinked = 0;

	glewInit();

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	DEBUG_MSG(glGetString(GL_VENDOR));
	DEBUG_MSG(glGetString(GL_RENDERER));
	DEBUG_MSG(glGetString(GL_VERSION));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glTranslated(0.0f, 0.0f, -10.0f);
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	/* Vertices counter-clockwise winding */
	vertex[0].coordinate[0] = -1.0f;	//bottom left f 0
	vertex[0].coordinate[1] = -1.0f;
	vertex[0].coordinate[2] = 1.0f;

	vertex[1].coordinate[0] = -1.0f ;	//top left f   1
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

	vertex[6].coordinate[0] = 1.0f ;		//top right b  6
	vertex[6].coordinate[1] = 1.0f;
	vertex[6].coordinate[2] = -1.0f;

	vertex[7].coordinate[0] = 1.0f;		//bottom right b 7
	vertex[7].coordinate[1] = -1.0f;
	vertex[7].coordinate[2] = -1.0f;


	vertex[0].color[0] = 0.0f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;
	vertex[0].color[3] = 1.0f;

	vertex[1].color[0] = 0.5f;
	vertex[1].color[1] = 0.5f;
	vertex[1].color[2] = 0.0f;
	vertex[1].color[3] = 1.0f;

	vertex[2].color[0] = 1.0f;
	vertex[2].color[1] = 0.0f;
	vertex[2].color[2] = 0.0f;
	vertex[2].color[3] = 1.0f;

	vertex[3].color[0] = 1.0f;
	vertex[3].color[1] = 0.0f;
	vertex[3].color[2] = 1.0f;
	vertex[3].color[3] = 1.0f;

	vertex[4].color[0] = 0.0f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;
	vertex[4].color[3] = 1.0f;

	vertex[5].color[0] = 0.5f;
	vertex[5].color[1] = 0.5f;
	vertex[5].color[2] = 0.0f;
	vertex[5].color[3] = 1.0f;

	vertex[6].color[0] = 1.0f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 0.0f;
	vertex[6].color[3] = 1.0f;

	vertex[7].color[0] = 1.0f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;
	vertex[7].color[3] = 1.0f;

	vertex[0].texel[0] = 0.5f;
	vertex[0].texel[1] = 0.5f;

	vertex[1].texel[0] = 1.0f;
	vertex[1].texel[1] = 1.0f;

	vertex[2].texel[0] = 1.0f;
	vertex[2].texel[1] = 0.0f;

	vertex[3].texel[0] = 0.5f;
	vertex[3].texel[1] = 0.5f;

	vertex[4].texel[0] = 1.0f;
	vertex[4].texel[1] = 1.0f;

	vertex[5].texel[0] = 1.0f;
	vertex[5].texel[1] = 0.0f;

	vertex[6].texel[0] = 0.5f;
	vertex[6].texel[1] = 0.5f;

	vertex[7].texel[0] = 1.0f;
	vertex[7].texel[1] = 1.0f;

	

	/*Index of Poly / Triangle to Draw */
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

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 7, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	///* Vertex Shader which would normally be loaded from an external file */
	

	


	std::string temp = loadShader("Shader.vs.txt");
	const char* vs_src = temp.c_str();
	
	DEBUG_MSG("Setting Up Vertex Shader");
	
	vsid = glCreateShader(GL_VERTEX_SHADER); //Create Shader and set ID
	glShaderSource(vsid, 1, (const GLchar**)&vs_src, NULL); // Set the shaders source
	glCompileShader(vsid); //Check that the shader compiles


	glGetShaderiv(vsid, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Vertex Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Vertex Shader Compilation Error");
	}



	std::string temp1 = loadShader("Shader.fv.txt");
	const char* fs_src = temp1.c_str();

	DEBUG_MSG("Setting Up Fragment Shader");

	fsid = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fsid, 1, (const GLchar**)&fs_src, NULL);
	glCompileShader(fsid);

	//Check is Shader Compiled
	glGetShaderiv(fsid, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Fragment Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Fragment Shader Compilation Error");
	}

	DEBUG_MSG("Setting Up and Linking Shader");
	progID = glCreateProgram();	//Create program in GPU
	glAttachShader(progID, vsid); //Attach Vertex Shader to Program
	glAttachShader(progID, fsid); //Attach Fragment Shader to Program
	glLinkProgram(progID);
	

	glGetProgramiv(progID, GL_LINK_STATUS, &isLinked);

	if (isLinked == 1) {
		DEBUG_MSG("Shader Linked");
	}
	else
	{
		DEBUG_MSG("ERROR: Shader Link Error");
	}

	// Use Progam on GPU
	// https://www.opengl.org/sdk/docs/man/html/glUseProgram.xhtml
	glUseProgram(progID);

	img_data = stbi_load(filename.c_str(), &width, &height, &comp_count, 4);

	if (img_data == NULL)
	{
		DEBUG_MSG("ERROR: Texture not loaded");
	}

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &to);
	glBindTexture(GL_TEXTURE_2D, to);

	//Wrap around
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Filtering
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	//Bind to OpenGL
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexImage2D.xml
	glTexImage2D(GL_TEXTURE_2D, //2D Texture Image
		0, //Mipmapping Level 
		GL_RGBA, //GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_RGB, GL_BGR, GL_RGBA 
		width, //Width
		height, //Height
		0, //Border
		GL_RGBA, //Bitmap
		GL_UNSIGNED_BYTE, img_data);

	// Find variables in the shader
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glGetAttribLocation.xml
	positionID = glGetAttribLocation(progID, "sv_position");
	colorID = glGetAttribLocation(progID, "sv_color");
	texelID = glGetAttribLocation(progID, "sv_texel");
	textureID = glGetUniformLocation(progID, "f_texture");
}

void Game::update()
{
	glCullFace(GL_BACK);

#if (DEBUG >= 2)
	DEBUG_MSG("Update up...");
#endif

}

void Game::render()
{
	glEnable(GL_STENCIL_TEST);
#if (DEBUG >= 2)
	DEBUG_MSG("Drawing...");
#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 8, vertex, GL_STATIC_DRAW);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain
		model components that 'are' and 'are not' to be drawn )	*/

		//Set Active Texture .... 32
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(textureID, 0);

	// Set pointers for each parameter
	// https://www.opengl.org/sdk/docs/man4/html/glVertexAttribPointer.xhtml
	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(texelID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	//Enable Arrays
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	glEnableVertexAttribArray(texelID);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	window.display();

}

void Game::unload()
{
#if (DEBUG >= 2)
	DEBUG_MSG("Cleaning up...");
#endif
	glDeleteProgram(progID);
	glDeleteBuffers(1, vbo);
	stbi_image_free(img_data); //Free image
}
void Game::transformCube(Matrix3 &matrix)
{
	for (int i = 0; i < 8; i++)
	{

		m_cubePoints[i] = Vector3(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);
		m_cubePoints[i] = Vector3((m_cubePoints[i].M_X() + inverse(m_centrePoint.M_X())), (m_cubePoints[i].M_Y() + inverse(m_centrePoint.M_Y())), (m_cubePoints[i].M_Z() + inverse(m_centrePoint.M_Z())));


		m_cubePoints[i] = matrix * m_cubePoints[i];

		m_cubePoints[i] = Vector3(m_cubePoints[i].M_X() + m_centrePoint.M_X(), m_cubePoints[i].M_Y() + m_centrePoint.M_Y(), m_cubePoints[i].M_Z() + m_centrePoint.M_Z());

		vertex[i].coordinate[0] = m_cubePoints[i].M_X();
		vertex[i].coordinate[1] = m_cubePoints[i].M_Y();
		vertex[i].coordinate[2] = m_cubePoints[i].M_Z();
	}
}

void Game::translatePoints(double translation, const Matrix3::Axis & axis)
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

void Game::moveCentrePoint(double translation, const Matrix3::Axis& axis)
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

float Game::inverse(float number)
{
	if (number < 0)
	{
		number = -number;
	}
	else if (number > 0)
	{
		number = -number;
	}
	return number;
}

