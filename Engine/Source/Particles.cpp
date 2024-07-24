#include "Particles.h"

void Particle::Update(float dt)
{
	if (m_lifespan != 0) m_lifespan -= dt;
	m_position = m_position + (m_velocity * dt);
}

void Particle::Draw(Renderer& renderer)
{

	if (m_lifespan > 0) renderer.DrawRect(m_position.x, m_position.y, 4.0f, 4.0f);
}