#include <iostream>
#include "Matrix3.h"
int main()
{
	Matrix3 m(2,2,1,
			  1,-2,3,
			  1,4,5);
	Matrix3 m1(4, 6, 1,
			   6, 3, 2,
			   7, 3, 1);

	Vector3 v(3, 2, 5);

	Matrix3 answer;
	answer = m * m1;
	
	std::cout << m.Inverse().toString() << std::endl;

	system("pause");
}