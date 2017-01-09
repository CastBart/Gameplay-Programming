#include "Cube.h"


using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void transformCube(Matrix3 &);
	void translatePoints(double translation, const Matrix3::Axis &axis);

	void update();
	void render();
	void unload();
	Vector3 m_cubePoints[8];
	Matrix3 matrix;
	sf::Clock clock;
	sf::Time elapsed;

	Cube m_cube;

	float rotationAngle = 0.0f;
};