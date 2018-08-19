#pragma once
namespace gravision {
	// real is single pressision for now
	typedef float real;


	class Vec3 {
	public:
		real x;
		real y;
		real z;
	private:
		real padding; //padding to ensure four word alignment in array usage
	public:
		//default constructor
		Vec3() : x(0), y(0), z(0) {}

		//explicit constructor
		Vec3(const real x, const real y, const real z) 
		: x(x), y(y), z(z) {}

		//flips all elements of the vector
		void Invert() {
			x = -x;
			y = -y;
			z = -z;
		}
	};
};

