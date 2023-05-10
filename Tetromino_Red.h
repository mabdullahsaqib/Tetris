#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
using namespace sf;

class Tetromino_Red : public Tetromino
{
private:
	int tetromino;
	int Board[20][10];

public:
	Tetromino_Red();
	void GetBoard(int array[][10])override;
	void SetBoard(int array[][10])override;
	bool CheckBoard(float x, float y, int rotated);
	void CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)override;
	int ReturnBoardValue(float x, float y);
	void SetBoardValue(float x, float y, int rotated);
	void RotateTetromino(RenderWindow& window, Sprite tetromino[], Texture red, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)override;
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture red, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard, float levelspeed)override;
	void Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])override;
};

Tetromino_Red::Tetromino_Red()
{
	tetromino = 7;
}

void Tetromino_Red::SetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = Board[i][j];
		}
	}
}

bool Tetromino_Red::CheckBoard(float x, float y, int rotated)
{
	int check = 0;
	if (rotated == 0)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y + 81.0f) != 0 || ReturnBoardValue(x + 106.0f, y + 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x + 106.0f, y) != 0 || ReturnBoardValue(x + 159.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x, y + 40.5f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 1)
	{
		if (ReturnBoardValue(x, y + 81.0f) != 0 || ReturnBoardValue(x - 53.0f, y + 121.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x, y + 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 106.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 106.0f, y + 81.0f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 2)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 106.0f, y) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x, y - 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x - 106.0f, y) != 0 || ReturnBoardValue(x - 159.0f, y - 40.5f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 3)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 106.0f, y - 40.5f) != 0 || ReturnBoardValue(x + 106.0f, y - 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y - 40.5f) != 0 || ReturnBoardValue(x, y - 81.0f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
}

void Tetromino_Red::CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)
{

	for (int i = 0, j = 8.0f, k = 162.0f; i < 4; i++)
	{

		if (i == 2)
		{
			j += 40.5f;
			k -= 53.0f;
		}
		blocks[i].setScale(Vector2f(0.55f, 0.5f));
		blocks[i].setTexture(texture);
		blocks[i].setPosition(k, j);
		k += 53.0f;
	}
	x = 162.0f;
	y = 8.0f;
	v = 53.0f;
	z = 8.0f;
}

void Tetromino_Red::GetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Board[i][j] = array[i][j];
		}
	}
}

int Tetromino_Red::ReturnBoardValue(float x, float y)
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

void Tetromino_Red::SetBoardValue(float x, float y, int rotated)
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
					Board[i][j + 1] = tetromino;
					Board[i + 1][j + 1] = tetromino;
					Board[i + 1][j + 2] = tetromino;
				}
				else if (rotated == 1)
				{
					Board[i][j] = tetromino;
					Board[i + 1][j] = tetromino;
					Board[i + 1][j - 1] = tetromino;
					Board[i + 2][j - 1] = tetromino;
				}
				else if (rotated == 2)
				{
					Board[i][j] = tetromino;
					Board[i][j - 1] = tetromino;
					Board[i - 1][j - 1] = tetromino;
					Board[i - 1][j - 2] = tetromino;
				}
				else if (rotated == 3)
				{
					Board[i][j] = tetromino;
					Board[i - 1][j] = tetromino;
					Board[i - 1][j + 1] = tetromino;
					Board[i - 2][j + 1] = tetromino;
				}
				return;
			}
			a += 53.0f;

		}
		b += 40.5f;
	}
}

void Tetromino_Red::Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])
{
	for (int i = 0; i < 4; i++)
	{
		tetromino[i].setTexture(color);
		window.draw(tetromino[i]);
	}
}


void Tetromino_Red::RotateTetromino(RenderWindow& window, Sprite tetromino[], Texture red, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		if (rotation == 3)
			rotation = 0;
		else
			rotation++;

		if (rotation == 0)
		{
			if (rotation == 0 && x < 420 && y < 777&& ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 40.5f) == 0)
			{
				if (x <420 && y<777)
				{
					for (int i = 0, j = y, k = x; i < 4; i++)
					{

						if (i == 2)
						{
							j += 40.5f;
							k -= 53.0f;
						}
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(red);
						tetromino[i].setPosition(k, j);
						k += 53.0f;
					}
				}
				else
					rotation = 3;
			}
			else
				rotation = 3;
		}
		if (rotation == 1)
		{
			if (rotation == 1 && x > 50 && y < 730 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 81.0f) == 0)
			{
				if (x > 50 && y<730)
				{
					for (int i = 0, j = y, k = x; i < 4; i++)
					{

						if (i == 2)
						{
							j -= 40.5f;
							k -= 53.0f;
						}
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(red);
						tetromino[i].setPosition(k, j);
						j += 40.5f;
					}

				}
				else
					rotation = 0;
			}
			else
				rotation = 0;
		}
		if (rotation == 2)
		{
			if (rotation == 2 && x >100 && y>10 &&  ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y - 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y - 40.5f) == 0)
			{
				if (x > 100 && y>10)
				{
					for (int i = 0, j = y, k = x; i < 4; i++)
					{

						if (i == 2)
						{
							j -= 40.5f;
							k += 53.0f;
						}
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(red);
						tetromino[i].setPosition(k, j);
						k -= 53.0f;
					}
				}
				else
					rotation = 1;
			}
			else
				rotation = 1;
		}
		if (rotation == 3)
		{
			if (rotation == 3 && y > 50 && x < 480 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y - 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y - 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y - 81.0f) == 0)
			{
				if (y > 50 && x < 480)
				{
					for (int i = 0, j = y, k = x; i < 4; i++)
					{

						if (i == 2)
						{
							j += 40.5f;
							k += 53.0f;
						}
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(red);
						tetromino[i].setPosition(k, j);
						j -= 40.5f;
					}

				}
				else
					rotation = 2;
			}
			else
				rotation = 2;
		}
	}
	return;
}

void Tetromino_Red::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture red, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard, float levelspeed)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x < 370 && ReturnBoardValue(x + 106.0f, y) == 0 && ReturnBoardValue(x+159.0f, y + 40.5f) == 0)
			{
				x += v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		else if (rotation == 1)
		{
			if (x < 470 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x, y + 81.0f) == 0)
			{
				x += v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j += 40.5f;
				}
			}

		}
		else if (rotation == 2)
		{
			if (x < 470 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x, y - 40.5f) == 0)
			{
				x += v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k -= 53.0f;
				}
			}
		}
		else if (rotation == 3)
		{
			if (x < 420 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 106.0f, y - 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y - 81.0f) == 0)
			{
				x += v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j -= 40.5f;
				}
			}
		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x > 10 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x , y + 40.5f) == 0)
			{
				x -= v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		else if (rotation == 1)
		{
			if (x > 60 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 81.0f) == 0)
			{
				x -= v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j += 40.5f;
				}
			}

		}
		else if (rotation == 2)
		{
			if (x > 150 && ReturnBoardValue(x - 106.0f, y) == 0 && ReturnBoardValue(x-159.0f, y - 40.5f) == 0)
			{
				x -= v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k -= 53.0f;
				}
			}
		}
		else if (rotation == 3)
		{
			if (x > 10 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y - 40.5f) == 0 && ReturnBoardValue(x, y - 81.0f) == 0)
			{
				x -= v;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j -= 40.5f;
				}
			}
		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (y < 730 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 81.0f) == 0 && ReturnBoardValue(x + 106.0f, y + 81.0f) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
		}
		else if (rotation == 1)
		{
			if (y < 690 && ReturnBoardValue(x, y + 81.0f) == 0 && ReturnBoardValue(x - 53.0f, y+121.5f) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j += 40.5f;
				}
			}

		}
		else if (rotation == 2)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y) == 0)
			{
				y += 40.5;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k -= 53.0f;
				}
			}
		}
		else if (rotation == 3)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j -= 40.5f;
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
			if (y < 730 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 81.0f) == 0 && ReturnBoardValue(x + 106.0f, y + 81.0f) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k += 53.0f;
				}
			}
			else
				checkboard = 0;
		}
		else if (rotation == 1)
		{
			if (y < 690 && ReturnBoardValue(x, y + 81.0f) == 0 && ReturnBoardValue(x - 53.0f, y + 121.5f) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k -= 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j += 40.5f;
				}
			}
			else
				checkboard = 0;
		}
		else if (rotation == 2)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y) == 0)
			{
				y += 40.5;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j -= 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					k -= 53.0f;
				}
			}
			else
				checkboard = 0;
		}
		else if (rotation == 3)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y) == 0)
			{
				y += 40.5f;
				for (int i = 0, j = y, k = x; i < 4; i++)
				{

					if (i == 2)
					{
						j += 40.5f;
						k += 53.0f;
					}
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(red);
					tetromino[i].setPosition(k, j);
					j -= 40.5f;
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