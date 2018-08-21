#pragma once
#include <gravision/core.h>
namespace gravision {
	class Particle {
	protected:
		//Everything below is relative to world space
		//holds the current position vector
		gravision::Vec3 position;
		//holds the current velocity vector
		gravision::Vec3 velocity;
		//holds the current acceleration vector
		gravision::Vec3 acceleration;

		//linear damping - used as a energi remover. works like a simple drag 0 to 1
		gravision::real damping;

		//Holds the inverse mass of the particle.
		//this way a 0 inverse object is as close one can get to an infinite mass (making it unable to accelerate)
		//a higher number is a lower mass
		//removes any chance of division with zero mass
		gravision::real inverseMass;
	public:
		//integrates the particle position from velocity and the velocity from the acceleration
		//uses the Newton-Euler integral method for linear approximation
		//dt = delta time = frame duration
		void Intergrate(const gravision::real dt);
		
		void SetMass(const gravision::real mass);

		void SetVelocity(const gravision::Vec3& vel);

		void SetPosition(const gravision::Vec3& worldPos);

		void SetAcceleration(const gravision::Vec3& acc);

		void SetDamping(const gravision::real drag);

		gravision::real GetMass()const;
		void GetMass(gravision::real *mass) const;

		gravision::real GetInverseMass()const;
		void GetInverseMass(gravision::real *InverseMass) const;

		gravision::Vec3 GetVelocity()const;
		void GetVelocity(gravision::Vec3 *vel)const;

		gravision::Vec3 GetPosition()const;
		void GetPosition(gravision::Vec3 *pos)const;

		gravision::Vec3 GetAcceleration()const;
		void GetAcceleration(gravision::Vec3 *acc)const;

		gravision::real GetDamping()const;
		void GetDamping(gravision::real *damping)const;

	};
}