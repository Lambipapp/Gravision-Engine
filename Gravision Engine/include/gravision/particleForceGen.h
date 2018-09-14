#pragma once
#include <gravision/core.h>
#include <gravision/particle.h>
class particleForceGen
{
public:
	particleForceGen();
	~particleForceGen();
	virtual void updateForce(gravision::Particle *particle, gravision::real dt) = 0;
};


