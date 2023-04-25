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
	virtual void CreateTetromino(Sprite* blocks, Texture texture,float& x, float& y, float& z, float& v);
};

Tetromino::Tetromino()
{
	tetromino = 1;
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
	return;
}

void Tetromino::CreateTetromino(Sprite* blocks, Texture texture,float& x, float& y, float& z, float& v)
{
	//if (tetromino == 1)
	//{
	//	Tetromino_Blue blue;
	//	blue.CreateTetromino(blocks, texture,x,y,z,v);
	//}
}
