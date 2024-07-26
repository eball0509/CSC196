#include "Bullet.h"
#include "Engine.h"

void Bullet::Update(float dt)
{
	m_velocity = Vector2{ 1, 0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}

void Bullet::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy")
	{
		for (int i = 0; i < 3; i++)
		{
		Particle::Data data{
			m_transform.position,
			Vector2(1,0).Rotate(randomf(Math::TwoPi)) * 50,
			randomf(0.5f,2.0f),
			100,100,100,100, };
		g_engine.GetPS().AddParticle(data);

		}
	}
}