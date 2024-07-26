#pragma once
#include "Vector2.h"
#include <vector>
#include <array>
using namespace std;


class Input{
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();
	void Update();

	bool GetKeyDown(uint8_t key) { return k_keyboardState[key]; }
	bool GetPrevKeyDown(uint8_t key) { return k_prevKeyboardState[key]; }


	Vector2 GetMousePosition() { return m_mousePosition; }
	bool GetMouseButtonDown(uint8_t button) { return m_mouseButtonStates[button]; }
	bool GetPreviousMouseButtonDown(uint8_t button) { return m_prevMouseButtonStates[button]; }

private:
	vector<uint8_t> k_keyboardState;
	vector<uint8_t> k_prevKeyboardState;

	Vector2 m_mousePosition{ 0, 0 };
	array<uint8_t, 3> m_mouseButtonStates{ 0,0,0 };
	array<uint8_t, 3> m_prevMouseButtonStates;
	
};