#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Well.h"
using namespace sf;

class Tetromino
{
private:
	int tetromino;
public:
	Tetromino();

};

Tetromino::Tetromino()
{
	tetromino = 0;
}
