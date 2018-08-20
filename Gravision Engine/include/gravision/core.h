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

		// calculates and returns the component product of 2 vectors. (I had not learned about this product before this)
		Vec3 ComponentProduct(const Vec3& v) const {
			return Vec3(x * v.x, y * v.y, z * v.z);
		}

		//Overwrites this vector with the compontentproduct from this*v
		void ComponentProductUpdate(const Vec3& v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
		}

		//returns the dotProduct by overwriting * operator
		real operator * (const Vec3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}
		//same thing as the * operator in the above overwrite
		real Dot(const Vec3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}

		//returns the crossproduct (normal) between the two vectors
		Vec3 Cross(const Vec3& v) const {
			return Vec3(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x
			);
		}
		// overvrites %= with crossproduct
		void operator %=(const Vec3& v) {
			*this = Cross(v);
		}
		//overwrites % opperator
		//returns the crossproduct (normal) between the two vectors
		Vec3 operator %(const Vec3& v) const {
			return Vec3(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x
			);
		}

		//a will remain as is but will become a unit vector, b might become shifted and scaled, c is only needed for output
		void OrthonormalBasis(Vec3 *a, Vec3 *b, Vec3 *c) {
			a->Normalize();
			*c = (*a) % (*b);
			if (c->SquareMagnitude() == 0.0) return; // this means that a and b are parrarell
			c->Normalize();
			*b = (*c) % (*a);
		}
	};
};

