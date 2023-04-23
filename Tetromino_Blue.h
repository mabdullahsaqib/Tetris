#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Well.h"
using namespace sf;

class Tetromino_Blue 
{
private:
	int tetromino;
	int** Board;
public:
	Tetromino_Blue();
	int GetTetromino();
	void GetBoard(int array[][10]);
	void SetBoard(int array[][10]);
	int ReturnBoardValue(float x, float y);
	void Rotation(RenderWindow& window,Sprite tetromino[],Texture blue, bool& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid);
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid);
	~Tetromino_Blue();
};

Tetromino_Blue::Tetromino_Blue()
{
	tetromino = 1;
	Board = nullptr;
}

int Tetromino_Blue::GetTetromino()
{
	return tetromino;
}

void Tetromino_Blue::SetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = Board[i][j];
		}
	}
}

void Tetromino_Blue::GetBoard(int array[][10])
{
	delete[]Board;
	Board = new int* [20];
	for (int i = 0; i < 20; i++)
	{
		Board[i] = new int[10];
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j] = array[i][j];
		}
	}
}

int Tetromino_Blue :: ReturnBoardValue(float x, float y)
{
	float a = 3.0f, b = 8.0f;
	for (int i = 0; i < 20; i++)
	{
		a = 3.0f;
		for (int j = 0; j < 10; j++)
		{
			if (x == a && y == b)
				return Board[i][j];
			else
			{
				a += 53.0f;
			}
		}
		b += 40.5f;
	}
}


void Tetromino_Blue::Rotation(RenderWindow& window, Sprite tetromino[],Texture blue, bool& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		rotation = !rotation;
		if (rotation == 0 && y < 670 && ReturnBoardValue(x,y) == 0 && ReturnBoardValue(x, y+40.5f) == 0 && ReturnBoardValue(x, y+81.0f) == 0 && ReturnBoardValue(x, y+121.5) == 0 )
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
		if (rotation == 1 && x < 350 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x+53.0f, y) == 0 && ReturnBoardValue(x+106.0f, y) == 0 && ReturnBoardValue(x+159.0f, y) == 0 )
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
	window.clear();
	window.draw(bg);
	for (int i = 0; i < 4; i++)
	{
		window.draw(tetromino[i]);
	}
	window.draw(Grid);
	window.display();
	return;
}

void Tetromino_Blue::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
	{
		if (rotation == 0 )
		{
			if (x < 466 && ReturnBoardValue(x+53.0f, y) == 0 && ReturnBoardValue(x+53.0f, y + 40.5f) == 0 && ReturnBoardValue(x+53.0f, y + 81.0f) == 0 && ReturnBoardValue(x+53.0f, y + 121.5) == 0)
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
		else if (rotation == 1 )
		{
			if (x < 300 && ReturnBoardValue(x + 212.0f, y) == 0)
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
		if (rotation == 0 )
		{
			if (x > 50 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 81.0f) == 0 && ReturnBoardValue(x - 53.0f, y + 121.5) == 0)
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
			if (x > 50 && ReturnBoardValue(x - 53.0f, y) == 0)
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
			if (y < 640 && ReturnBoardValue(x, y+40.5f) == 0)
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
		else if (rotation == 1 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x+53.0f, y + 40.5f) == 0 && ReturnBoardValue(x+106.0f, y + 40.5f) == 0 && ReturnBoardValue(x+159.0f, y + 40.5f) == 0)
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
	if (elaspedtime > 1.0)
	{
		if (rotation == 0 )
		{
			if (y < 640 && ReturnBoardValue(x, y + 40.5f) == 0)
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
			if (y < 760 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 159.0f, y + 40.5f) == 0)
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
	window.clear();
	window.draw(bg);
	for (int i = 0; i < 4; i++)
	{
		window.draw(tetromino[i]);
	}
	window.draw(Grid);
	window.display();
	return;
}

Tetromino_Blue::~Tetromino_Blue()
{
	for (int i = 0; i < 20; i++)
	{
		delete[]Board[i];
	}
	delete[]Board;
}
