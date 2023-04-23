#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Well.h"
#include"Tetromino.h"
using namespace sf;

class Tetromino_Blue 
{
private:
	int tetromino = 1;
public:
	int GetTetromino();
	void Rotation(RenderWindow& window,Sprite tetromino[],Texture blue, bool& rotation, float& x, float& y, float& z, float& v);
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime);
};

int Tetromino_Blue::GetTetromino()
{
	return tetromino;
}

void Tetromino_Blue::Rotation(RenderWindow& window, Sprite tetromino[],Texture blue, bool& rotation, float& x, float& y, float& z, float& v)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		rotation = !rotation;
		if (rotation == 0 && y < 670)
		{
			if (z < 670)
			{
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
			else
				rotation = 1;
		}
		else
			rotation = 1;
		if (rotation == 1 && x < 350)
		{
			z = x;
			if (z < 350)
			{
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z += v;
				}
			}
			else
				rotation = 0;
			z = y;
		}
		else
			rotation = 0;
	}
	return;
}

void Tetromino_Blue::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x < 466)
			{
				x += v;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (x < 300)
			{
				x += v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, y);
					x += v;
				}
				x = z;
				z = y;
			}

		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x > 50)
			{
				x -= v;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (x > 50)
			{
				x -= v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, y);
					x += v;
				}
				x = z;
				z = y;
			}
		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (y < 640)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (y < 760)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, y);
					x += v;
				}
				x = z;
				z = y;
			}
		}
		switchtime = 0;
	}
	else if (elaspedtime > 1.0)
	{
		if (rotation == 0)
		{
			if (y < 640)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (y < 760)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, y);
					x += v;
				}
				x = z;
				z = y;
			}
		}
		elaspedtime = 0.0;
	}
	return;
}
