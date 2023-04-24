#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Tetromino_Blue.h"
using namespace sf;

class Well
{
private:
	int well[20][10];
public:
	Well();
	void Board(RenderWindow& window);
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

	//Sets the blue that is I Shaped Tetromino
	Texture blue;
	blue.loadFromFile("Textures/Tetromino_blue_block.png");

	Sprite* tetromino;
	tetromino = nullptr;
	
	Tetromino_Blue blue_t;

	Clock clock;
	float x = 268.0f;
	float y = 8.0f;
	float v = 53.0f;
	float z = 8.0f;
	float deltatime;
	float switchtime = 0.0;
	float elaspedtime = 0.0;
	bool isrotated = 0;
	bool checkboard = 0;


	while (window.isOpen())
	{
		Event e;
		deltatime = clock.restart().asSeconds();
		switchtime += deltatime;
		elaspedtime += deltatime;
		if (checkboard == 0)
		{
			delete[]tetromino;
			tetromino = new Sprite[4];
			for (int i = 0, j = 8.0; i < 4; i++, j += 40.5)
			{
				tetromino[i].setScale(Vector2f(0.55f, 0.5f));
				tetromino[i].setTexture(blue);
				tetromino[i].setPosition(268.0, j);
			}
			 x = 268.0f;
			 y = 8.0f;
			 v = 53.0f;
			 z = 8.0f;
			 isrotated = 0;
		}
		

		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;


			}

			blue_t.GetBoard(well);
			blue_t.Rotation(window, tetromino, blue, isrotated, x, y, z, v, bg, Grid);
			blue_t.SetBoard(well);
		}

		blue_t.GetBoard(well);
		blue_t.MoveTetromino(window, tetromino, blue, isrotated, x, y, z, v, switchtime, elaspedtime, bg, Grid,checkboard);
		blue_t.SetBoard(well);
	}
	return;
}

