#pragma once
#include <cmath>

struct Vector2
{
	float x, y;

	Vector2() = default;
	Vector2(float x, float y) { this->x = x; this->y = y; }
	Vector2(int x, int y) { this->x = x; this->y = y; }

	Vector2 operator + (Vector2 v) const { return Vector2{ x + v.x, y + v.y }; }
	Vector2 operator - (Vector2 v) const { return Vector2{ x - v.x, y - v.y }; }
	Vector2 operator * (Vector2 v) const { return Vector2{ x * v.x, y * v.y }; }
	Vector2 operator / (Vector2 v) const { return Vector2{ x / v.x, y / v.y }; }

	Vector2 operator + (float v) const { return Vector2{ x + v, y + v }; }
	Vector2 operator - (float v) const { return Vector2{ x - v, y - v }; }
	Vector2 operator * (float v) const { return Vector2{ x * v, y * v }; }
	Vector2 operator / (float v) const { return Vector2{ x / v, y / v }; }

	float LengthSqr() { return ((x * x) + (y * y)); }
	float Length() { return ( sqrt( (x * x) + (y * y))); }

};
