#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
using namespace sf;

class Tetromino_Yellow : public Tetromino
{
private:
	int tetromino;
	int Board[20][10];

public:
	Tetromino_Yellow();
	void GetBoard(int array[][10])override;
	void SetBoard(int array[][10])override;
	bool CheckBoard(float x, float y, int rotated);
	void CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)override;
	int ReturnBoardValue(float x, float y);
	void SetBoardValue(float x, float y, int rotated);
	void RotateTetromino(RenderWindow& window, Sprite tetromino[], Texture yellow, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)override;
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture yellow, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard, float levelspeed)override;
	void Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])override;
};

Tetromino_Yellow::Tetromino_Yellow()
{
	tetromino = 4;
}

void Tetromino_Yellow::SetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = Board[i][j];
		}
	}
}

bool Tetromino_Yellow::CheckBoard(float x, float y, int rotated)
{
	int check = 0;
	if (rotated == 0)
	{
		if (ReturnBoardValue(x, y + 81.0f) != 0 || ReturnBoardValue(x + 53.0f, y + 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x + 106.0f, y) != 0 || ReturnBoardValue(x + 106.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	
}

void Tetromino_Yellow::CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)
{
	for (int i = 0, j = 8.0f, k = 215.0f; i < 4; i++)
	{

		if (i == 2)
		{
			j += 40.5f;
			k = 215.0f;
		}
		blocks[i].setScale(Vector2f(0.55f, 0.5f));
		blocks[i].setTexture(texture);
		blocks[i].setPosition(k, j);
		k += 53.0f;
	}
	x = 215.0f;
	y = 8.0f;
	v = 53.0f;
	z = 8.0f;

}

void Tetromino_Yellow::GetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j] = array[i][j];
		}
	}
}

int Tetromino_Yellow::ReturnBoardValue(float x, float y)
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
	return -1;
}

void Tetromino_Yellow::SetBoardValue(float x, float y, int rotated)
{
	float a = 3.0f, b = 8.0f;
	for (int i = 0; i < 20; i++)
	{
		a = 3.0f;
		for (int j = 0; j < 10; j++)
		{
			if (x == a && y == b)
			{
				if (rotated == 0)
				{
					Board[i][j] = tetromino;
					Board[i ][j+1] = tetromino;
					Board[i + 1][j] = tetromino;
					Board[i + 1][j+1] = tetromino;
				}
				
				return;
			}

			else
			{
				a += 53.0f;
			}
		}
		b += 40.5f;
	}
}

void Tetromino_Yellow::Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])
{
	for (int i = 0; i < 4; i++)
	{
		tetromino[i].setTexture(color);
		window.draw(tetromino[i]);
	}
}


void Tetromino_Yellow::RotateTetromino(RenderWindow& window, Sprite tetromino[], Texture yellow, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)
{
		rotation = 0;	
	return;
}

void Tetromino_Yellow::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture yellow, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard, float levelspeed)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x < 425 && ReturnBoardValue(x + 106.0f, y) == 0 && ReturnBoardValue(x + 106.0f, y + 40.5f) == 0)
			{
				x += v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{
					if (i == 2)
					{
						j += 40.5f;
						k = x;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(yellow);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		switchtime = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x >50 && ReturnBoardValue(x -53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0)
			{
				x -= v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{
					if (i == 2)
					{
						j += 40.5f;
						k = x;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(yellow);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		switchtime = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.0)
	{
		if (rotation == 0)
		{
			if (y < 700 && ReturnBoardValue(x , y+81.0f) == 0 && ReturnBoardValue(x + 53.0f, y + 81.0f) == 0)
			{
				y += 40.5f;

				for (int i = 0, j = y, k = x; i < 4; i++)
				{
					if (i == 2)
					{
						j += 40.5f;
						k = x;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(yellow);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		switchtime = 0;
	}
	checkboard = CheckBoard(x, y, rotation);
	if (elaspedtime > levelspeed)
	{
		if (rotation == 0)
		{
			if (y < 700 && ReturnBoardValue(x, y + 81.0f) == 0 && ReturnBoardValue(x + 53.0f, y + 81.0f) == 0)
			{
				y += 40.5f;

				for (int i = 0, j = y, k = x; i < 4; i++)
				{
					if (i == 2)
					{
						j += 40.5f;
						k = x;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(yellow);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
			else
				checkboard = 0;
		}
		elaspedtime = 0.0;
	}
	if (checkboard == 0)
		SetBoardValue(x, y, rotation);

	return;
}