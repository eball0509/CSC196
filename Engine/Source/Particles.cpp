#include "Particles.h"

void Particle::Update(float dt)
{
	position = position + (velocity * dt);
}

void Particle::Draw(Renderer& renderer)
{
	renderer.Drawpoint(position.x, position.y);
}
