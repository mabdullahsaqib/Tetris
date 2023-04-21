#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;

class Well
{
public:
	Well();
	void Board(RenderWindow& window);

private:
	int well[20][10];
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

inline void Well::Board(RenderWindow& window)
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
	//Grid.setFillColor(Color(255, 255, 255));
	Texture grid;
	grid.loadFromFile("Textures/Grid 10x20.png");
	Grid.setTexture(&grid);

	//Sets the blue that is I Shaped Tetromino
	Texture blue;
	blue.loadFromFile("Textures/Tetromino_blue_block.png");

	Sprite blue_tetromino[4];

	//	Sprite blue_tetromino;
	//blue_tetromino.setScale(Vector2f(0.55f, 0.5f));
	//blue_tetromino.setTexture(blue);
	//blue_tetromino.setPosition(3.0f, 8.0f);

	for (int i = 0,  j = 8.0; i < 4; i++, j += 40.5)
	{
		blue_tetromino[i].setScale(Vector2f(0.55f, 0.5f));
		blue_tetromino[i].setTexture(blue);
		blue_tetromino[i].setPosition(3.0, j);
	}

	Clock clock;
	float x = 3.0f;
	float y = 8.0f;
	float v = 53.0f;
	float z = 8.0f;
	float deltatime;
	float switchtime = 0.0;
	float elaspedtime = 0.0;
	while (window.isOpen())
	{
		Event e;
		deltatime = clock.restart().asSeconds();
		switchtime += deltatime;
		elaspedtime += deltatime;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;


			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
		{
			if (x < 466)
			{
				x += v;
				for (int i = 0; i < 4; i++)
				{
					blue_tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					blue_tetromino[i].setTexture(blue);
					blue_tetromino[i].setPosition(x,z);
					z += 40.5f;
				}
				z = y;
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
		{
			if (x > 50)
			{
				x -= v;
				for (int i = 0; i < 4; i++)
				{
					blue_tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					blue_tetromino[i].setTexture(blue);
					blue_tetromino[i].setPosition(x, z);
					z += 40.5;
				}
				z = y;
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
		{
			if (y < 760)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					blue_tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					blue_tetromino[i].setTexture(blue);
					blue_tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
			switchtime = 0;
		}
		if (elaspedtime > 1.0)
		{
			if (y < 760)
			{
				y += 40.5f;
				z = y;
				for (int i = 0; i < 4; i++)
				{
					blue_tetromino[i].setScale(Vector2f(0.55f, 0.5f));
					blue_tetromino[i].setTexture(blue);
					blue_tetromino[i].setPosition(x, z);
					z += 40.5f;
				}
				z = y;
			}
			elaspedtime = 0.0;
		}

		window.clear();
		window.draw(bg);
		for (int i = 0; i < 4; i++)
		{
			window.draw(blue_tetromino[i]);
		}
		window.draw(Grid);
		window.display();
	}
}
