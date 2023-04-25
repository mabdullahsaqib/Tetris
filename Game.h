#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Well.h"
using namespace sf;

class Game
{
private:
	Well well;
public:
	Game(RenderWindow& window);
};

Game::Game(RenderWindow& window)
{
	well.Board(window);
}
