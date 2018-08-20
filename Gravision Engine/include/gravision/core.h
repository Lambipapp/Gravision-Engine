#pragma once
#include <gravision/precision.h>
namespace gravision {
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

		//returns the magnitude of this vector
		real Magnitude() const {
			return real_sqrt(x*x + y*y + z*z);
		}

		// returns the squared magnitude of this vector
		real SquareMagnitude() const {
			return x * x + y * y + z * z;
		}

		//makes this vector to a unit vector as long as magnitude > 0
		void Normalize() {
			real l = Magnitude();
			if (l > 0) {
				(*this) *= ((real)1) / l;
			}
		}

		//overwrites the *= opperator for Vec3 uses
		void operator *= (const real scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
		}

		//overwriting the * opperator for Vec3 uses
		//returns a copy of this vec3 scaled to scalar
		Vec3 operator *(const real scalar) const {
			return Vec3(x*scalar, y*scalar, z*scalar);
		}

		//overwrites += of vec3-addition
		void operator +=(const Vec3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}

		//overwrites += of vec3-subtraction
		void operator -=(const Vec3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}

		//overwrites + of vec3-addition
		//returns a new Vec3 
		Vec3 operator +(const Vec3& v) const {
			return Vec3(x + v.x, y + v.y, z + v.z);
		}
		//overwrites - of vec3-subtraction
		//returns a new Vec3 
		Vec3 operator -(const Vec3& v) const {
			return Vec3(x - v.x, y - v.y, z - v.z);
		}
	};
};

