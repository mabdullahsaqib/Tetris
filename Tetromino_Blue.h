#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
using namespace sf;

class Tetromino_Blue : public Tetromino
{
private:
	int tetromino;
	int Board[20][10];

public:
	Tetromino_Blue();
	void GetBoard(int array[][10])override;
	void SetBoard(int array[][10])override;
	bool CheckBoard(float x , float y, int rotated);
	void CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)override;
	int ReturnBoardValue(float x, float y);
	void SetBoardValue(float x, float y, int rotated);
	void RotateTetromino(RenderWindow& window,Sprite tetromino[],Texture blue, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)override;
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid,bool& checkboard)override;
	void Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])override;
};

Tetromino_Blue::Tetromino_Blue() 
{
	tetromino = 1;
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

bool Tetromino_Blue::CheckBoard(float x, float y, int rotated)
{
	int check = 0;
	if (rotated == 0)
	{
		if (ReturnBoardValue(x, y + 162) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y + 81.0f) != 0 || ReturnBoardValue(x + 53.0f, y + 121.5) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y + 81.0f) != 0 || ReturnBoardValue(x - 53.0f, y + 121.5) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 1)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 106.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 159.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0)
			check++;
		if (ReturnBoardValue(x - 212.0f, y) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 2)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y - 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y - 81.0f) != 0 || ReturnBoardValue(x + 53.0f, y - 121.5) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y - 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y - 81.0f) != 0 || ReturnBoardValue(x - 53.0f, y - 121.5) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 3)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x + 106.0f, y + 40.5f) != 0 || ReturnBoardValue(x + 159.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 212.0f, y) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
}

void Tetromino_Blue::CreateTetromino(Sprite* blocks, Texture texture, float& x, float& y, float& z, float& v)
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

void Tetromino_Blue::GetBoard(int array[][10])
{
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
	return -1;
}

void Tetromino_Blue::SetBoardValue(float x, float y, int rotated)
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
					Board[i+1][j] = tetromino;
					Board[i+2][j] = tetromino;
					Board[i+3][j] = tetromino;
				}
				else if (rotated == 1)
				{
					Board[i][j] = tetromino;
					Board[i][j-1] = tetromino;
					Board[i][j-2] = tetromino;
					Board[i][j-3] = tetromino;
				}
				else if (rotated == 2)
				{
					Board[i][j] = tetromino;
					Board[i-1][j] = tetromino;
					Board[i-2][j] = tetromino;
					Board[i-3][j] = tetromino;
				}
				else if (rotated == 3)
				{
					Board[i][j] = tetromino;
					Board[i][j+1] = tetromino;
					Board[i][j+2] = tetromino;
					Board[i][j+3] = tetromino;
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

void Tetromino_Blue::Draw(RenderWindow& window, Texture& color, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])
{
	for (int i = 0; i < 4; i++)
	{
		tetromino[i].setTexture(color);
		window.draw(tetromino[i]);
	}
}

void Tetromino_Blue::RotateTetromino(RenderWindow& window, Sprite tetromino[],Texture blue, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		if (rotation == 3)
			rotation = 0;
		else
			rotation++;
		if (rotation == 0)
		{
			if (rotation == 0 && y < 670 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x, y + 81.0f) == 0 && ReturnBoardValue(x, y + 121.5) == 0)
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
					rotation = 3;
			}
			else
				rotation = 3;

		}
		if (rotation == 1)
		{
			if (rotation == 1 && x >120 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y) == 0 && ReturnBoardValue(x - 159.0f, y) == 0)
			{
				z = x;
				if (z > 120)
				{
					for (int i = 0; i < 4; i++)
					{
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(blue);
						tetromino[i].setPosition(z, y);
						z -= v;
					}
				}
				else
					rotation = 0;
				z = y;
			}
			else
				rotation = 0;
		}
		if (rotation == 2)
		{
			if (rotation == 2 && y > 100 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y - 40.5f) == 0 && ReturnBoardValue(x, y - 81.0f) == 0 && ReturnBoardValue(x, y - 121.5) == 0)
			{
				if (z > 100)
				{
					for (int i = 0; i < 4; i++)
					{
						tetromino[i].setScale(Vector2f(0.55f, 0.5f));
						tetromino[i].setTexture(blue);
						tetromino[i].setPosition(x, z);
						z -= 40.5f;
					}
					z = y;
				}
				else
					rotation = 1;
			}
			else
				rotation = 1;
		}
		if (rotation == 3)
		{
			if (rotation == 3 && x < 350 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 106.0f, y) == 0 && ReturnBoardValue(x + 159.0f, y) == 0)
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
					rotation = 2;
				z = y;
			}
			else
				rotation = 2;
		}
	}
	return;
}

void Tetromino_Blue::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid,bool& checkboard)
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
		else if (rotation == 1)
		{
			if (x < 450 && ReturnBoardValue(x + 53.0f, y) == 0)
			{
				x += v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z -= v;
				}
				z = y;
			}

		}
		else if (rotation == 2 )
		{
			if (x < 466 && ReturnBoardValue(x+53.0f, y) == 0 && ReturnBoardValue(x+53.0f, y - 40.5f) == 0 && ReturnBoardValue(x+53.0f, y - 81.0f) == 0 && ReturnBoardValue(x+53.0f, y - 121.5) == 0)
			{
				x += v;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z -= 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 3 )
		{
			if (x < 300 && ReturnBoardValue(x + 212.0f, y) == 0)
			{
				x += v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z += v;
				}
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
			if (x > 165 && ReturnBoardValue(x - 212.0f, y) == 0)
			{
				x -= v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z -= v;
				}
				z = y;
			}
		}
		else if (rotation == 2 )
		{
			if (x > 50 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y - 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y - 81.0f) == 0 && ReturnBoardValue(x - 53.0f, y - 121.5) == 0)
			{
				x -= v;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z -= 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 3)
		{
			if (x > 50 && ReturnBoardValue(x - 53.0f, y) == 0)
			{
				x -= v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z += v;
				}
				z = y;
			}
		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (y < 640 && ReturnBoardValue(x, y+162.0f) == 0)
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
			if (y < 760 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 159.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z -= v;
				}
				z = y;
			}
		}
		else if (rotation == 2)
		{
			if (y < 750 && ReturnBoardValue(x, y+40.5f) == 0)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z -= 40.5f;
				}
				z = y;
			}
		}
		else if (rotation == 3 )
		{
			if (y < 760 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 159.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z += v;
				}
				z = y;
			}
		}
		switchtime = 0;
	}
	checkboard = CheckBoard(x, y, rotation);
	if (elaspedtime > 1.0)
	{
		if (rotation == 0)
		{
			if (y < 640 && ReturnBoardValue(x, y + 162.0f) == 0)
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
			else
				checkboard = 0;
		}
		else if (rotation == 1)
		{
			if (y < 760 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 159.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z -= v;
				}
				z = y;
			}
			else
				checkboard = 0;
		}
		else if (rotation == 2)
		{
			if (y < 750 && ReturnBoardValue(x, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(x, z);
					z -= 40.5f;
				}
				z = y;
			}
			else
				checkboard = 0;
		}
		else if (rotation == 3)
		{
			if (y < 760 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 159.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					tetromino[i].setTexture(blue);
					tetromino[i].setPosition(z, y);
					z += v;
				}
				z = y;
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