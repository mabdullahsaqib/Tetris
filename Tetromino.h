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
	void CreateTetromino(Sprite* blocks, Texture texture,float& x, float& y, float& z, float& v);
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
	return;
}

void Tetromino::CreateTetromino(Sprite* blocks, Texture texture,float& x, float& y, float& z, float& v)
{
	if (tetromino == 1)
	{
		for (int i = 0, j = 8.0; i < 4; i++, j += 40.5)
		{
			blocks[i].setScale(Vector2f(0.55f, 0.5f));
			blocks[i].setTexture(texture);
			blocks[i].setPosition(215.0, j);
		}
		x = 215.0f;
		y = 8.0f;
		v = 53.0f;
		z = 8.0f;
	}
	else if (tetromino == 2)
	{
		for (int i = 0, j = 8.0; i < 4; i++, j += 40.5)
		{
			if (i != 3)
			{
				blocks[i].setScale(Vector2f(0.61f, 0.5f));
				blocks[i].setTexture(texture);
				blocks[i].setPosition(215.0, j);
			}
			else
			{
				j -= 40.5;
				blocks[i].setScale(Vector2f(0.61f, 0.5f));
				blocks[i].setTexture(texture);
				blocks[i].setPosition(162.0, j);
			}
			
		}
		x = 215.0f;
		y = 8.0f;
		v = 53.0f;
		z = 8.0f;
	}
}

