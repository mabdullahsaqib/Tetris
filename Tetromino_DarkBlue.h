#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
using namespace sf;

class Tetromino_DarkBlue : public Tetromino
{
private:
	int tetromino;
	int** Board;
public:
	Tetromino_DarkBlue();
	int GetTetromino();
	void GetBoard(int array[][10]);
	void SetBoard(int array[][10]);
	bool CheckBoard(float x, float y, int rotated);
	int ReturnBoardValue(float x, float y);
	void SetBoardValue(float x, float y, int rotated);
	void Rotation(RenderWindow& window, Sprite tetromino[], Texture darkblue, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid);
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture darkblue, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard);
	void Draw(RenderWindow& window, Texture& darkblue, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[]);
	~Tetromino_DarkBlue();
};

Tetromino_DarkBlue::Tetromino_DarkBlue()
{
	tetromino = 2;
	Board = nullptr;
}

int Tetromino_DarkBlue::GetTetromino()
{
	return tetromino;
}

void Tetromino_DarkBlue::SetBoard(int array[][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = Board[i][j];
		}
	}
}

bool Tetromino_DarkBlue::CheckBoard(float x, float y, int rotated)
{
	int check = 0;
	if (rotated == 0)
	{
		if (ReturnBoardValue(x, y + 121.5f) != 0 || ReturnBoardValue(x - 53.0f, y + 121.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y + 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 106.0f, y + 81.0f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 1)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x - 106.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y - 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x - 159.0f, y) != 0 || ReturnBoardValue(x - 159.0f, y - 40.5f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 2)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y - 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x + 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y - 40.5f) != 0 || ReturnBoardValue(x + 106.0f, y - 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x - 53.0f, y - 40.5f) != 0 || ReturnBoardValue(x - 53.0f, y - 81.0f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}
	else if (rotated == 3)
	{
		if (ReturnBoardValue(x, y + 40.5f) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0 || ReturnBoardValue(x + 106.0f, y + 81.0f) != 0)
			check++;
		if (ReturnBoardValue(x + 159.0f, y) != 0 || ReturnBoardValue(x + 159.0f, y + 40.5f) != 0)
			check++;
		if (ReturnBoardValue(x - 53.0f, y) != 0 || ReturnBoardValue(x + 53.0f, y + 40.5f) != 0)
			check++;
		if (check == 3)
			return false;
		return true;
	}

}

void Tetromino_DarkBlue::GetBoard(int array[][10])
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

int Tetromino_DarkBlue::ReturnBoardValue(float x, float y)
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

void Tetromino_DarkBlue::SetBoardValue(float x, float y, int rotated)
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
					Board[i + 1][j] = tetromino;
					Board[i + 2][j] = tetromino;
					Board[i + 2][j-1] = tetromino;
				}
				if (rotated == 1)
				{
					Board[i][j] = tetromino;
					Board[i][j - 1] = tetromino;
					Board[i][j - 2] = tetromino;
					Board[i-1][j -2] = tetromino;
				}
				if (rotated == 2)
				{
					Board[i][j] = tetromino;
					Board[i-1][j] = tetromino;
					Board[i-2][j] = tetromino;
					Board[i-2][j + 1] = tetromino;
				}
				if (rotated == 3)
				{
					Board[i][j] = tetromino;
					Board[i][j + 1] = tetromino;
					Board[i][j + 2] = tetromino;
					Board[i+1][j + 2] = tetromino;
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

void Tetromino_DarkBlue::Draw(RenderWindow& window, Texture& darkblue, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])
{
	Sprite tetrominos;
	tetrominos.setScale(Vector2f(0.61f, 0.5f));
	tetrominos.setTexture(darkblue);

	float a = 3.0f, b = 8.0f;


	window.clear();
	for (int i = 0; i < 4; i++)
	{
		window.draw(tetromino[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		a = 3.0f;
		for (int j = 0; j < 10; j++)
		{
			if (Board[i][j] == this->tetromino)
			{
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}

			a += 53.0f;
		}
		b += 40.5f;
	}

	window.draw(Grid);
	window.display();


}


void Tetromino_DarkBlue::Rotation(RenderWindow& window, Sprite tetromino[], Texture darkblue, int& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		if (rotation == 3)
			rotation = 0;
		else
			rotation++;
	
		if (rotation == 0)
		{
			if (rotation == 0 && y < 700 && x>55 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x, y + 81.0f) == 0 && ReturnBoardValue(x - 53.0f, y + 81.0f) == 0)
			{
				if (z < 700 && x>55)
				{
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
						{
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(x, z);
							z += 40.5f;
						}
						else
						{
							z -= 40.5;
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(x - v, z);
						}
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
			if (rotation == 1 && x > 110 && y > 45 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y - 40.5) == 0)
			{
				z = x;
				if (z > 110 && y > 45)
				{
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
						{
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(z, y);
							z -= v;
						}
						else
						{
							z += v;
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(z, y - 40.5);
						}
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
			if (rotation == 2 && y > 90 && x < 480 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x, y - 40.5f) == 0 && ReturnBoardValue(x, y - 81.0f) == 0 && ReturnBoardValue(x + 53.0f, y - 81.0f) == 0)
			{
				if (z > 90 && x < 480)
				{
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
						{
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(x, z);
							z -= 40.5f;
						}
						else
						{
							z += 40.5f;
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(x + v, z);
						}
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
			if (rotation == 3 && y < 777.5 && x < 425 && ReturnBoardValue(x, y) == 0 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y) == 0 && ReturnBoardValue(x - 106.0f, y - 40.5) == 0)
			{
				z = x;
				if (z < 777.5 && x < 425)
				{
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
						{
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(z, y);
							z += v;
						}
						else
						{
							z -= v;
							tetromino[i].setScale(Vector2f(0.61f, 0.5f));
							tetromino[i].setTexture(darkblue);
							tetromino[i].setPosition(z, y + 40.5);
						}
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
	Draw(window, darkblue, bg, Grid, tetromino);
	return;
}

void Tetromino_DarkBlue::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture darkblue, int& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid, bool& checkboard)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x < 466 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 81.0f) == 0 )
			{
				x += v;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z += 40.5f;
					}
					else
					{
						z -= 40.5;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x - v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (x < 466 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x-53.0f,y-40.5f) == 0)
			{
				x += v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z -= v;
					}
					else
					{
						z += v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y - 40.5);
					}
				}
				z = y;
			}

		}
		else if (rotation == 2)
		{
			if (x < 420 && ReturnBoardValue(x + 53.0f, y) == 0 && ReturnBoardValue(x + 53.0f, y - 40.5) == 0 && ReturnBoardValue(x + 106.0f, y - 81.0f) == 0)
			{
				x += v;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z -= 40.5f;
					}
					else
					{
						z += 40.5f;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x + v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 3)
		{
			if (x < 330 && ReturnBoardValue(x + 159.0f, y) == 0 && ReturnBoardValue(x + 159.0f, y + 40.5f) == 0)
			{
				x += v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z += v;
					}
					else
					{
						z -= v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y + 40.5);
					}
				}
				z = y;
			}
		}
		switchtime = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
	{
		if (rotation == 0)
		{
			if (x >108 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 81.0f) == 0)
			{
				x -= v;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z += 40.5f;
					}
					else
					{
						z -= 40.5;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x - v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (x >150 && ReturnBoardValue(x - 159.0f, y) == 0 && ReturnBoardValue(x - 159.0f, y - 40.5f) == 0)
			{
				x -= v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z -= v;
					}
					else
					{
						z += v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y - 40.5);
					}
				}
				z = y;
			}

		}
		else if (rotation == 2)
		{
			if (x >50 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x - 53.0f, y - 40.5) == 0 && ReturnBoardValue(x - 53.0f, y - 81.0f) == 0)
			{
				x -= v;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z -= 40.5f;
					}
					else
					{
						z += 40.5f;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x + v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 3)
		{
			if (x >50 && ReturnBoardValue(x - 53.0f, y) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0)
			{
				x -= v;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z += v;
					}
					else
					{
						z -= v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y + 40.5);
					}
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
			if (y < 660 && ReturnBoardValue(x, y+121.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 121.5f) == 0)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z += 40.5f;
					}
					else
					{
						z -= 40.5;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x - v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 1)
		{
			if (y<777 && ReturnBoardValue(x, y+40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z -= v;
					}
					else
					{
						z += v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y - 40.5);
					}
				}
				z = y;
			}

		}
		else if (rotation == 2)
		{
			if (y < 777 && ReturnBoardValue(x , y+40.5f) == 0 && ReturnBoardValue(x + 53.0f, y - 40.5) == 0 )
			{
				y += 40.5;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z -= 40.5f;
					}
					else
					{
						z += 40.5f;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x + v, z);
					}
				}
				z = y;
			}
		}
		else if (rotation == 3)
		{
			if (y < 730 && ReturnBoardValue(x, y+40.5f) == 0 && ReturnBoardValue(x+53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 81.0f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z += v;
					}
					else
					{
						z -= v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y + 40.5);
					}
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
			if (y < 660 && ReturnBoardValue(x, y + 121.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 121.5f) == 0)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z += 40.5f;
					}
					else
					{
						z -= 40.5;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x - v, z);
					}
				}
				z = y;
			}
			else
				checkboard = 0;
		}
		else if (rotation == 1)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x - 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x - 106.0f, y + 40.5f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z -= v;
					}
					else
					{
						z += v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y - 40.5);
					}
				}
				z = y;
			}
			else
				checkboard = 0;
		}
		else if (rotation == 2)
		{
			if (y < 777 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y - 40.5) == 0)
			{
				y += 40.5;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x, z);
						z -= 40.5f;
					}
					else
					{
						z += 40.5f;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(x + v, z);
					}
				}
				z = y;
			}
			else
				checkboard = 0;
		}
		else if (rotation == 3)
		{
			if (y < 730 && ReturnBoardValue(x, y + 40.5f) == 0 && ReturnBoardValue(x + 53.0f, y + 40.5f) == 0 && ReturnBoardValue(x + 106.0f, y + 81.0f) == 0)
			{
				y += 40.5f;
				z = x;
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
					{
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y);
						z += v;
					}
					else
					{
						z -= v;
						tetromino[i].setScale(Vector2f(0.61f, 0.5f));
						tetromino[i].setTexture(darkblue);
						tetromino[i].setPosition(z, y + 40.5);
					}
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

	Draw(window, darkblue, bg, Grid, tetromino);
	return;
}

Tetromino_DarkBlue::~Tetromino_DarkBlue()
{
	for (int i = 0; i < 20; i++)
	{
		delete[]Board[i];
	}
	delete[]Board;
}
