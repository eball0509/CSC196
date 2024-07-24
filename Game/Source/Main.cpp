#include "Engine.h"

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {

	g_engine.Initialize();


	Input input;
	input.Initialize();

	Time time;

	vector<Particle> particles;

	float offset = 0;

	Font* font = new Font();
	font->Load("ArcadeClassic.ttf", 20);

	Text* text = new Text(font);

	// create audio system
	FMOD::System* audio;
	FMOD::System_Create(&audio);

	

	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	FMOD::Sound* sound = nullptr;
	audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

	audio->playSound(sound, 0, false, nullptr);

	std::vector<FMOD::Sound*> sounds;
	
	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);


	bool quit = false;
	vector<Vector2> points;
	while (!quit)
	{

		time.Tick();
		g_engine.Update();
		audio->update();



		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		Vector2 mousePosition = input.GetMousePosition();
		if (input.getMouseButtonDown(0))
		{
			for (int i = 0; i < 100; i++)
			{
				particles.push_back(Particle{ mousePosition, RandomUnitOnCircle() * (10, 30) });
			}
		}



		for (Particle& particle : particles) {
			particle.Update(time.GetDeltaTime());
			if (particle.m_position.x > 800) particle.m_position.x = 0;
			if (particle.m_position.x < 0) particle.m_position.x = 800;
			if (particle.m_position.y > 600) particle.m_position.y = 0;
			if (particle.m_position.y < 0) particle.m_position.y = 600;
		}


		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q))
		{
			audio->playSound(sounds[0], 0, false, nullptr);
		};

		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W))
		{
			audio->playSound(sounds[1], 0, false, nullptr);
		};

		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E))
		{
			audio->playSound(sounds[2], 0, false, nullptr);
		};
	
		
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

		
		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();
		
		

		float radius = 60;
		offset += (90 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30) {
			float x = Math::Cos(Math::DegToRad(angle * offset)) * Math::Sin(offset + angle) * 0.1f * radius;
			float y = Math::Sin(Math::DegToRad(angle * offset)) * Math::Sin(offset + angle) * 0.1f * radius;

			g_engine.GetRenderer().DrawRect(400 + x, 300 + y, 4.0f, 4.0f);
		}

		for (Particle particle : particles) {
			particle.Draw(g_engine.GetRenderer());
		}
		
		text->Create(g_engine.GetRenderer(), "Hello World", Color{ 1, 1, 1, 1 });
		text->Draw(g_engine.GetRenderer(), 40, 40);
		
		g_engine.GetRenderer().EndFrame();

	}
	return 0;
}