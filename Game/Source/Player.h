#pragma once
#include "Actor.h"


class Player : public Actor
{
public:

	Player() = default;
	Player(const Transform& transform) : Actor{ transform } {}
	Player(const Transform& transform, Model* model) : Actor{ transform, model } {}
	Player(float speed, const Transform& transform, Model* model) : Actor{ transform, model }, m_speed{ speed } {}
	
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	
	void SetFireModifier(float mod) { m_fireModifier = mod; }

private:

	float m_speed = 80000;
	float m_fireTimer = 0;
	float m_fireModifier = 1;
};