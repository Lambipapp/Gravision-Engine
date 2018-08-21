#include <iostream>
#include <gravision/core.h>
#include <gravision/particle.h>
#include <GL/GLFW/glfw3.h>


void ExesChap2();
void TestParticle();

struct Projectile {
	gravision::Particle particle;
};
int main() {
	
	//ExesChap2();
	//TestParticle();


	std::system("Pause");
	return 0;
}

void TestParticle() {
	Projectile *p = new Projectile();
	p->particle.SetMass(20.0f);
	p->particle.SetVelocity(gravision::Vec3(1.0f, -1.0f, 2.0f));
	p->particle.SetAcceleration(gravision::Vec3(0.0f, 1.0f, -1.0f));
	p->particle.SetDamping(1.0f);
	p->particle.SetPosition(gravision::Vec3(1.0f, 2.0f, 3.0f));

	for (int i = 0; i < 5; i++) {
		p->particle.Intergrate(1.0f);
	}
}

void ExesChap2() {
	// EX2.1		Decompose the following vector [2, -2, -2].
	gravision::Vec3 exVec0 = gravision::Vec3(2, -2, -2);
	std::cout << "Vector: {" << exVec0.x << ", " << exVec0.y << ", " << exVec0.z << " decomposes to: " << std::endl;
	gravision::real magnitudeOfV = exVec0.Magnitude();
	exVec0.Normalize();
	std::cout << "Magnitude: " << magnitudeOfV << std::endl << "Unit of vector: " << exVec0.x << ", " << exVec0.y << ", " << exVec0.z << std::endl << std::endl;

	// EX2.2 Calculate the scalar product (dot) from vectors: [3,1,2][0,2,-1]
	gravision::Vec3 exVec1 = gravision::Vec3(3, 1, 2);
	gravision::Vec3 exVec2 = gravision::Vec3(0, 2, -1);
	gravision::real scalarVal = exVec1 * exVec2;
	std::cout << "The dotproduct of vectors v and u is: " << std::endl;
	std::cout << "v = [" << exVec1.x << ", " << exVec1.y << ", " << exVec1.z << "]" << std::endl;
	std::cout << "u = [" << exVec2.x << ", " << exVec2.y << ", " << exVec2.z << "]" << std::endl;
	std::cout << "dot prudoct / scalar product: " << scalarVal << std::endl << std::endl;
	// vectors were orthogonal

	// EX2.3 Calculate the dot product of a vector with itself
	gravision::real selfDot = exVec1 * exVec1; // is the same as calling the "exVec1.SquareMagnitude()" function 
	std::cout << "dot product result from using the same vector as both parameters: " << selfDot << std::endl << std::endl;

	// EX2.5 use the dot product to find the angle between [0,1,1] and [0,-1,0]
	gravision::Vec3 exVec3 = gravision::Vec3(0, 1, 1);
	gravision::Vec3 exVec4 = gravision::Vec3(0, -1, 0);
	gravision::real exTheta = acos((exVec3 * exVec4) / (exVec3.Magnitude() * exVec4.Magnitude()));
	std::cout << "angle is between vectors [0,1,1] and [0,-1,0] is: " << exTheta << " radians"<<  std::endl << std::endl;

	// EX2.6
	gravision::Vec3 exVec5 = gravision::Vec3(0, 1, 1);
	exVec5 *= (1 / real_sqrt(2));
	gravision::Vec3 exVec6 = gravision::Vec3(1, 2, 3);
	gravision::real scalarC = exVec5 * exVec6;
	gravision::Vec3 exVec7 = exVec6 - (exVec5 * scalarC);
	std::cout << "exVec5 = [" << exVec5.x << ", " << exVec5.y << ", " << exVec5.z << "]" << std::endl;
	std::cout << "ScalarC = " << scalarC << std::endl;
	std::cout << "(exVec5 * scalarC) = [" << (exVec5 * scalarC).x << ", " << (exVec5 * scalarC).y << ", " << (exVec5 * scalarC).z << "]" << std::endl;
	std::cout << "exVec6 = [" << exVec6.x << ", " << exVec6.y << ", " << exVec6.z << "]" << std::endl;
	std::cout << "exVec7 = [" << exVec7.x << ", " << exVec7.y << ", " << exVec7.z << "]" << std::endl << std::endl;

	// EX2.7
	gravision::Vec3 pos = gravision::Vec3(1, 2, 3);
	gravision::Vec3 constantVel = gravision::Vec3(1, -1, 2);

	std::cout << "position Before 10 steps with velocity [1, -1, 2]: [" << pos.x << ", " << pos.y << ", " << pos.z << "]" << std::endl;
	for (int i = 0; i < 10; i++) {
		pos += constantVel;
	}
	std::cout << "position after 10sek: ["<< pos.x << ", "<< pos.y << ", " << pos.z <<"]" << std::endl;
}


