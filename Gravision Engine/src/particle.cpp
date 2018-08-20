#include <gravision/particle.h>
#include <assert.h>

void Particle::Intergrate(gravision::real dt) {
	//leave if mass is infinite
	//might add error handling later
	if (inverseMass <= 0) return;

	assert(dt > 0.0);

	//updates linear position relative to framerate
	position.AddScaledVector(velocity, dt);

	//for now the acceleration is not effected by anything else than the set acceleration.
	//we will ad a forceAccumulator later
	gravision::Vec3 frameAcc = acceleration;

	//updetes linear velocity form the frameAcc vector
	velocity.AddScaledVector(frameAcc, dt);

	//impose drag
	velocity *= real_pow(damping, dt);

	//clearAccumulator(); //add later when accumulator is implemented
}