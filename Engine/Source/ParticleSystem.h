#pragma once
#include "Particles.h"
#include <vector>

class ParticleSystem
{
public:
	ParticleSystem(int maxSize = 10000)
	{
		m_particles.resize(maxSize);
	}

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddParticle(const Particle::Data& data);

private:
	Particle* GetFreeParticle();
	std::vector<Particle> m_particles;
};

