#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
using namespace sf;

class Tetromino_Blue : public Tetromino
{
private:
	int tetromino;
	int** Board;
public:
	Tetromino_Blue();
	int GetTetromino();
	void GetBoard(int array[][10]);
	void SetBoard(int array[][10]);
	bool CheckBoard(float x , float y, bool rotated);
	int ReturnBoardValue(float x, float y);
	void SetBoardValue(float x, float y, bool rotated);
	void Rotation(RenderWindow& window,Sprite tetromino[],Texture blue, bool& rotation, float& x, float& y, float& z, float& v, RectangleShape& bg, RectangleShape& Grid);
	void MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid,bool& checkboard);
	void Draw(RenderWindow& window, Texture& blue, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[]);
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

bool Tetromino_Blue::CheckBoard(float x, float y, bool rotated)
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
	return -1;
}

void Tetromino_Blue::SetBoardValue(float x, float y, bool rotated)
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

void Tetromino_Blue::Draw(RenderWindow& window, Texture& blue, RectangleShape& bg, RectangleShape& Grid, Sprite tetromino[])
{
	Sprite tetrominos;
	tetrominos.setScale(Vector2f(0.55f, 0.5f));
	tetrominos.setTexture(blue);

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
	
	Draw(window,blue,bg,Grid,tetromino);
	return;
}

void Tetromino_Blue::MoveTetromino(RenderWindow& window, Sprite tetromino[], Texture blue, bool& rotation, float& x, float& y, float& z, float& v, float& switchtime, float& elaspedtime, RectangleShape& bg, RectangleShape& Grid,bool& checkboard)
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
		else if (rotation == 1 )
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
		switchtime = 0;
	}
	checkboard = CheckBoard(x, y, rotation);
	if (elaspedtime > 1.0)
	{
		if (rotation == 0 )
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
			else
				checkboard = 0;
		}
		elaspedtime = 0.0;
	}
	if (checkboard == 0)
		SetBoardValue(x, y, rotation);

	Draw(window, blue, bg, Grid, tetromino);

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
