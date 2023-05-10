#pragma once
#include<iostream>
#include<Windows.h>
#include<SFML/Graphics.hpp>
#include"Tetromino.h"
#include"Tetromino_Blue.h"
#include"Tetromino_DarkBlue.h"
#include"Tetromino_Orange.h"
#include"Tetromino_Yellow.h"
#include"Tetromino_Green.h"
#include"Tetromino_Purple.h"
#include"Tetromino_Red.h"
using namespace sf;

class Well
{
private:
	int well[20][10];
	int score;
	int linescounter;
	int level;
public:
	Well();
	void Board(RenderWindow& window);
	void CheckForMatch(RenderWindow& window, int& lvl, float& levelspeed);
	void ScoreKeeper(RenderWindow& window, int match, int& lvl, float& levelspeed);
	void Draw(RenderWindow& window, RectangleShape& Grid);
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
	score = 0;
	linescounter = 0;
	level = 0;
}

void Well::Board(RenderWindow& window)
{
	//Sets the background for the window
	RectangleShape bg;
	bg.setSize(Vector2f(840.0f, 820.0f));
	bg.setPosition(0.0f, 0.0f);
	bg.setFillColor(Color(10,10,10));

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

	//Creates a pointer to dynamically allocate a size 4 array to hold tetromino during runtime
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
	int lvl = 0;
	float levelspeed = 1.0;

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
			CheckForMatch(window, lvl , levelspeed);
			random = (rand() % 7) + 1;
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
			else if (random == 6)
				tetromino = new Tetromino_Purple;
			else if (random == 7)
				tetromino = new Tetromino_Red;

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
		tetromino->MoveTetromino(window, blocks, texture, rotation, x, y, z, v, switchtime, elaspedtime, bg, Grid,checkboard, levelspeed);
		tetromino->SetBoard(well);

		window.clear();
		window.draw(bg);
		tetromino->Draw(window, texture, bg, Grid, blocks);
		Draw(window, Grid);
		ScoreKeeper(window, 0, lvl , levelspeed);
		window.display();
	}
	return;
}

void Well::CheckForMatch(RenderWindow& window, int& lvl, float& levelspeed)
{
	int match = 0, linescounter = 0, l;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (well[i][j] != 0)
				match++;
		}
		if (match == 10)
		{
		ScoreKeeper(window,match, lvl ,levelspeed);
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

void Well::Draw(RenderWindow& window, RectangleShape& Grid)
{
	Sprite tetrominos;
	Texture color;
	float a = 3.0f, b = 8.0f;

	for (int i = 0; i < 20; i++)
	{
		a = 3.0f;
		for (int j = 0; j < 10; j++)
		{
			if (well[i][j] == 1)
			{
				color.loadFromFile("Textures/Tetromino_blue_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 2)
			{
				color.loadFromFile("Textures/Tetromino_darkblue_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 3)
			{
				color.loadFromFile("Textures/Tetromino_orange_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 4)
			{
				color.loadFromFile("Textures/Tetromino_yellow_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 5)
			{
				color.loadFromFile("Textures/Tetromino_green_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 6)
			{
				color.loadFromFile("Textures/Tetromino_purple_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}
			else if (well[i][j] == 7)
			{
				color.loadFromFile("Textures/Tetromino_red_block.png");
				tetrominos.setTexture(color);
				tetrominos.setScale(Vector2f(0.55f, 0.5f));
				tetrominos.setPosition(a, b);
				window.draw(tetrominos);
			}

			a += 53.0f;
		}
		b += 40.5f;
	}
	window.draw(Grid);
	return;
}

void Well::ScoreKeeper(RenderWindow& window, int match, int& lvl, float& levelspeed)
{

	RectangleShape Border;
	Border.setSize(Vector2f(150.0f, 60.0f));
	Border.setFillColor(Color(210, 210, 210));
	for (int i = 0, y = 290.0f; i < 3; i++, y+=200.0f)
	{
		Border.setPosition(600.0f, y);
		window.draw(Border);
	}

	Font font;
	font.loadFromFile("Fonts/Lobster_1.3.otf");

	if (match == 10)
	{
		linescounter++;
		score += 100;
		lvl++;
	}

	Text Score("Score: " + std::to_string(score), font, 25);
	Score.setPosition(620.0f, 500.0f);
	Score.setFillColor(Color::Black);

	Text Lines("Lines: " + std::to_string(linescounter), font, 25);
	Lines.setPosition(620.0f, 700.0f);
	Lines.setFillColor(Color::Black);

	if (lvl == 10)
	{
		level++;
		lvl = 0;
		levelspeed -= 0.1;
		if (level == 8)
		{
			level = 0;
			levelspeed = 1.0;
		}
	}
	Text Level("Level# " + std::to_string(level), font, 25);
	Level.setPosition(620.0f, 300.0f);
	Level.setFillColor(Color::Black);


	std::cout << "Score = " << score << "  || Lines Completed = " << linescounter << "  || Level  = " << level << "\r";

	window.draw(Level);
	window.draw(Score);
	window.draw(Lines);
}
