#include "stdafx.h"

#include <iostream>
using namespace std;

#include "Game.h"


const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{

}


Game::~Game()
{
}


bool Game::init() {	
	Size2D winSize(800,600);

	renderer.init(winSize,"Simple SDL App");

	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);

	inputManager.AddListener(EventListener::Event::LEFT, this);
	inputManager.AddListener(EventListener::Event::RIGHT, this);
	inputManager.AddListener(EventListener::Event::DOWN, this);
	inputManager.AddListener(EventListener::Event::UP, this);
	inputManager.AddListener(EventListener::Event::UNDO, this);
	inputManager.AddListener(EventListener::Event::SPACE, this);

	return true;
}


void Game::destroy()
{

	renderer.destroy();
}

//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(0,0,0));// prepare for new frame
	

	renderer.present();
}

void Game::loop()
{

	int frameNum = 0;
	while (!quit) {

		inputManager.ProcessInput();
	}
}

void Game::onEvent(EventListener::Event evt) {

	if (evt == EventListener::Event::LEFT) {
		buttonA_->execute();
	//	cout << "Left" << endl;
	}
	
	if (evt == EventListener::Event::RIGHT) {
		buttonD_->execute();
	//	cout << "Right" << endl;
	}

	if (evt == EventListener::Event::DOWN) {
		buttonS_->execute();
		//cout << "Down" << endl;
	}

	if (evt == EventListener::Event::UP) {
		buttonW_->execute();
		//cout << "Up" << endl;
	}

	if (evt == EventListener::Event::UNDO) {
		buttonBS_->execute();
		//cout << "Undo" << endl;
	}

	if (evt == EventListener::Event::SPACE) {
		buttonSpace_->execute();
		//cout << "Space" << endl;
	}

}
