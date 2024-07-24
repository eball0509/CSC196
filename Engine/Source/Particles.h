#pragma once
#include "Vector2.h"
#include "Renderer.h"

//We are using struct here since we want all the data to be public
struct Particle
{
	Vector2 m_position{ 0, 0 };
	Vector2 m_velocity{ 0, 0 };
	float m_lifespan = 0;


	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) : m_position{ position }, m_velocity{ velocity } {}
	Particle(Vector2 position, Vector2 velocity, float lifespan) : m_position{ position }, m_velocity{ velocity }, m_lifespan{ lifespan } {}

	void Update(float dt);
	void Draw(Renderer& renderer);


};