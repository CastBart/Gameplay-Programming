#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <gl\GL.h>
#include <gl\GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game(ContextSettings);
	~Game();
	void run();
private:
	
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	void drawTriangle();
	void drawPoint();
	void drawLine();
	void drawLineStrip();
	void drawLineLoop();
	void drawTriangleStrip();
	void drawTriangleFan();
	void drawQuad();
	void drawQuadStrip();
	void drawPolygon();
};


//GL_POINTS GL_LINES GL_LINE_STRIP GL_LINE_LOOP GL_TRIANGLES GL_TRIANGLE_STRIP GL_TRIANGLE_FAN GL_QUADS GL_QUAD_STRIP GL_POLYGON