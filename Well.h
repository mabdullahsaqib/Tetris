#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Tetromino_Blue.h"
using namespace sf;

class Well
{
private:
	int well[20][10];
public:
	Well();
	void Board(RenderWindow& window);
	void CheckForMatch();
};

Well::Well()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			well[i][j] = 0;
		}
	}
}

void Well::Board(RenderWindow& window)
{
	//Sets the background for the window
	RectangleShape bg;
	bg.setSize(Vector2f(840.0f, 820.0f));
	bg.setPosition(0.0f, 0.0f);
	bg.setFillColor(Color(30, 30, 30));

	//Sets the Grid for the game
	RectangleShape Grid;
	Grid.setSize(Vector2f(530.0f, 809.25f));
	Grid.setPosition(0.0f, 5.0f);
	Texture grid;
	grid.loadFromFile("Textures/Grid 10x20.png");
	Grid.setTexture(&grid);

	srand(time(0));

	Tetromino tetromino;

	//Sets the texture of Tetromino
	Texture texture;
	

	Sprite* blocks;
	blocks = nullptr;
	
	Tetromino_Blue texture_t;

	Clock clock;
	float x;
	float y;
	float v;
	float z;
	float deltatime;
	float switchtime = 0.0;
	float elaspedtime = 0.0;
	bool isrotated = 0;
	bool checkboard = 0;
	int match=0;
	int random = 0;

	window.draw(bg);
	

	while (window.isOpen())
	{
		Event e;
		deltatime = clock.restart().asSeconds();
		switchtime += deltatime;
		elaspedtime += deltatime;
		if (checkboard == 0)
		{
			delete[]blocks;
			CheckForMatch();
			random = (rand() % 7) + 1;
			tetromino.SetTetromino(1);
			tetromino.SetTexture(texture);
			if (well[0][5] == 0)
			{
				blocks = new Sprite[4];
				/*for (int i = 0, j = 8.0; i < 4; i++, j += 40.5)
				{
					blocks[i].setScale(Vector2f(0.55f, 0.5f));
					blocks[i].setTexture(texture);
					blocks[i].setPosition(215.0, j);
				}
				x = 215.0f;
				y = 8.0f;
				v = 53.0f;
				z = 8.0f;*/
				tetromino.CreateTetromino(blocks, texture,x,y,z,v);
				isrotated = 0;
			}
			else
			{
				Sleep(1000);
				window.close();
				std::cout << "\n\nGame Over!!!!\n\n";
			}
		}
		

		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;


			}

			texture_t.GetBoard(well);
			texture_t.Rotation(window, blocks, texture, isrotated, x, y, z, v, bg, Grid);
			texture_t.SetBoard(well);

		}


		texture_t.GetBoard(well);
		texture_t.MoveTetromino(window, blocks, texture, isrotated, x, y, z, v, switchtime, elaspedtime, bg, Grid,checkboard);
		texture_t.SetBoard(well);

	}
	return;
}

void Well::CheckForMatch()
{
	int match = 0, l;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (well[i][j] != 0)
				match++;
		}
		if (match == 10)
		{
			for (int j = 0; j < 10; j++)
			{
				well[i][j] = 0;
			}
			l = i;
			for (int k = i - 1; k >= 0; k--)
			{
				for (int j = 0; j < 10; j++)
				{
					std::swap(well[l][j], well[k][j]);
				}
				l--;
			}
		}
		match = 0;
	}
}

