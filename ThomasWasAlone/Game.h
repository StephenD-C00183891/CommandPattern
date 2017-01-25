#pragma once

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "EventListener.h"
#include "Command.h"

/** The game objct whic manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	Renderer renderer;

	std::vector<GameObject*> gameObjects;

	bool quit = false;

	Command* buttonS_;
	Command* buttonW_;
	Command* buttonA_;
	Command* buttonD_;
	Command* buttonBS_;
	Command* buttonSpace_;

	unsigned int lastTime;//time of last update;

public:
	Game();
	~Game();

	bool init();
	void destroy();

	void render();
	void loop();

	void onEvent(EventListener::Event);
};

