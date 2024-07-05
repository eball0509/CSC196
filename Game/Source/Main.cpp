#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "ETime.h"
#include "Random.h"
#include "Particles.h"

#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Window", 800, 600);

	Input input;
	input.Initialize();

	Time time;

	vector<Particle> particles;


	bool quit = false;
	vector<Vector2> points;
	while (!quit)
	{
		time.Tick();
		
	
		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		Vector2 mousePosition = input.GetMousePosition();
		if (input.getMouseButtonDown(0)) 
		{
			for (int i = 0; i < 100; i++) 
			{
				particles.push_back(Particle{ mousePosition, { randomf(-300, 300), randomf(-300, 300)} });
			}
		}

		for (Particle& particle : particles) {
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
			if (particle.position.y > 600) particle.position.x = 0;
			if (particle.position.y < 0) particle.position.x = 600;
		}

		
		if (input.getMouseButtonDown(0) && !input.getPreviousMouseButtonDown(0)) {
			cout << "Mouse Pressed\n";
			points.push_back(mousePosition);
		}

		
		if (input.getMouseButtonDown(0) && input.getMouseButtonDown(0)) {
			cout << "Mouse Held\n";
			float distance = (points.back() - mousePosition).Length();
			if (distance > 3) {
				points.push_back(mousePosition);
			}
		}

		

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		renderer.SetColor(255, 255, 255, 0);
		for (Particle particle : particles) {
			particle.Draw(renderer);
		}

		
		renderer.EndFrame();

	}
	return 0;
}