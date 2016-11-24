#include <iostream>
#include "Vector3.h"


int main()
{

	Vector3 v = Vector3(2, 3, 1);
	Vector3 v1 = Vector3(4, 7, 2);
	//v= -v;
	std::cout << v.toString() << std::endl;
	system("pause");
}