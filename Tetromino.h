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
	void SetTetromino(int n);
	int GetTetromino();
	void SetTexture(Texture& texture);
	virtual void CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v) = 0;
	virtual void RotateTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid) =0;
	virtual void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard) = 0;
	virtual void GetBoard(int array[][10]) = 0;
	virtual void SetBoard(int array[][10]) = 0;
};

Tetromino::Tetromino()
{
	tetromino = 0;
}

void Tetromino::SetTetromino(int n)
{
	tetromino=n ;
}

int Tetromino::GetTetromino()
{
	return tetromino;
}

void Tetromino::SetTexture(Texture& texture)
{
	if (tetromino == 1)
		texture.loadFromFile("Textures/Tetromino_blue_block.png");
	else if (tetromino == 2)
		texture.loadFromFile("Textures/Tetromino_darkblue_block.png");
	else if (tetromino == 3)
		texture.loadFromFile("Textures/Tetromino_orange_block.png");
	else if (tetromino == 4)
		texture.loadFromFile("Textures/Tetromino_yellow_block.png");
	else if (tetromino == 5)
		texture.loadFromFile("Textures/Tetromino_green_block.png");
	else if (tetromino == 6)
		texture.loadFromFile("Textures/Tetromino_purple_block.png");
	else if (tetromino == 7)
		texture.loadFromFile("Textures/Tetromino_red_block.png");
	return;
}

