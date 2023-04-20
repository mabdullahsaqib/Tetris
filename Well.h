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
	blue.loadFromFile("Textures/Tetromino_I.png");

	Sprite blue_tetromino;
	blue_tetromino.setScale(Vector2f(0.7f, 0.57f));
	blue_tetromino.setTexture(blue);
	blue_tetromino.setPosition(3.0f, 8.0f);

	Clock clock;
    float x = 3.0f;
	float y = 8.0f;
	float v = 53.0f;
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
			if (e.type == Event::Closed)
				window.close();

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
		{
			if (x < 466)
			{
				x += v;
				blue_tetromino.setPosition(x, y);
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
		{
			if (x >50)
			{
				x -= v;
				blue_tetromino.setPosition(x, y);
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
		{
			if (y < 640)
			{
				y += 40.5f;
			blue_tetromino.setPosition(x, y);
			}
			switchtime = 0;
		}
		if (elaspedtime > 1.0)
		{
			if (y < 640)
			{
				y += 40.5f;
				blue_tetromino.setPosition(x, y);
			}
			elaspedtime = 0.0;
		}

		window.clear();
		window.draw(bg);
		window.draw(blue_tetromino);
		window.draw(Grid);
		window.display();
	}
}
