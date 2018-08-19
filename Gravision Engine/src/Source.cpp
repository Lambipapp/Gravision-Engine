#include <iostream>
#include <gravision/core.h>

using namespace std;
int main() {
	gravision::Vec3 v3 = gravision::Vec3(1, 2, 3);

	std::cout << v3.x << std::endl;
	v3.Invert();
	std::cout << v3.x << std::endl;

	return 0;
}