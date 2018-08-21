#include <gravision/particle.h>
#include <assert.h>

void gravision::Particle::Intergrate(gravision::real dt) {
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

void gravision::Particle::SetMass(const gravision::real mass)
{
	inverseMass = 1 / mass;
}

void gravision::Particle::SetVelocity(const gravision::Vec3& vel)
{
	velocity = vel;
}

void gravision::Particle::SetPosition(const gravision::Vec3& worldPos)
{
	position = worldPos;
}

void gravision::Particle::SetAcceleration(const gravision::Vec3& acc)
{
	acceleration = acc;
}

void gravision::Particle::SetDamping(const gravision::real drag)
{
	damping = drag;
}

gravision::real gravision::Particle::GetMass()const
{
	return (1 / inverseMass);
}

void gravision::Particle::GetMass(gravision::real * mass) const
{
	*mass = 1 / inverseMass;
}

gravision::real gravision::Particle::GetInverseMass() const
{
	return inverseMass;
}

void gravision::Particle::GetInverseMass(gravision::real * InverseMass) const
{
	*InverseMass = inverseMass;
}

gravision::Vec3 gravision::Particle::GetVelocity()const
{
	return velocity;
}

void gravision::Particle::GetVelocity(gravision::Vec3 * vel) const
{
	*vel = velocity;
}

gravision::Vec3 gravision::Particle::GetPosition()const
{
	return position;
}

void gravision::Particle::GetPosition(gravision::Vec3 * pos) const
{
	*pos = position;
}

gravision::Vec3 gravision::Particle::GetAcceleration()const
{
	return acceleration;
}

void gravision::Particle::GetAcceleration(gravision::Vec3 * acc) const
{
	*acc = acceleration;
}

gravision::real gravision::Particle::GetDamping()const
{
	return damping;
}

void gravision::Particle::GetDamping(gravision::real * drag) const
{
	*drag = damping;
}
