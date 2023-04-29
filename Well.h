#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Tetromino_Blue.h"
#include"Tetromino_DarkBlue.h"
#include"Tetromino_Orange.h"
#include"Tetromino_Yellow.h"
#include"Tetromino_Green.h"
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

	Tetromino *tetromino;
	tetromino = nullptr;

	//Sets the texture of Tetromino
	Texture texture;
	

	Sprite* blocks;
	blocks = nullptr;
	

	Clock clock;
	float x;
	float y;
	float v;
	float z;
	float deltatime;
	float switchtime = 0.0;
	float elaspedtime = 0.0;
	int rotation = 0;
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
			delete[]tetromino;
			CheckForMatch();
			random = (rand() % 5) + 1;
			if (random == 1)
				tetromino = new Tetromino_Blue;
			else if (random == 2)
				tetromino = new Tetromino_DarkBlue;
			else if (random == 3)
				tetromino = new Tetromino_Orange;
			else if (random == 4)
				tetromino = new Tetromino_Yellow;
			else if (random == 5)
				tetromino = new Tetromino_Green;

			tetromino->SetTetromino(random);
			tetromino->SetTexture(texture);
			if (well[0][4] == 0)
			{
				blocks = new Sprite[4];
				tetromino->CreateTetromino(blocks, texture, x, y, z, v);
				rotation = 0;

			}
			else
			{
				delete[]blocks;
				delete[]tetromino;
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
				delete[]blocks;
				delete[]tetromino;
				window.close();
				break;


			}

			tetromino->GetBoard(well);
			tetromino->RotateTetromino(window, blocks, texture, rotation, x, y, z, v, bg, Grid);
			tetromino->SetBoard(well);

		}


		tetromino->GetBoard(well);
		tetromino->MoveTetromino(window, blocks, texture, rotation, x, y, z, v, switchtime, elaspedtime, bg, Grid,checkboard);
		tetromino->SetBoard(well);

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
