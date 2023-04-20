#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;

class Well
{
public:
	Well();
	void Board(RenderWindow& window);

	~Well();

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

Well::~Well()
{

}

inline void Well::Board(RenderWindow& window)
{
	RectangleShape bg;
	bg.setSize(Vector2f(840.0f, 820.0f));
	bg.setPosition(0.0f, 0.0f);
	bg.setFillColor(Color(30, 30, 30));

	RectangleShape Grid;
	Grid.setSize(Vector2f(515.0f, 800.0f));
	Grid.setPosition(0.0f, 5.0f);
	Grid.setFillColor(Color(255, 255, 255));
	Texture grid;
	grid.loadFromFile("Textures/Grid 10x20.png");
	Grid.setTexture(&grid);

	//RectangleShape firstshape;
	//firstshape.setSize(Vector2f(45.0f, 33.0f));
	//firstshape.setPosition(3.0f, 8.0f);
	//firstshape.setFillColor(Color::Cyan);

	Texture blue;
	blue.loadFromFile("Textures/Tetromino_I.png");

	Sprite rectangleshape;
	rectangleshape.setScale(Vector2f(0.7f, 0.57f));
	rectangleshape.setTexture(blue);
	rectangleshape.setPosition(3.0f, 8.0f);

    float x = 3.0f;
	float v = 8.0f;
	Clock clock;
	float deltatime;
	float switchtime = 0.0;
	float y = 53.0f;
	while (window.isOpen())
	{
		Event e;
		deltatime = clock.restart().asSeconds();
		switchtime += deltatime;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

		}
		//if (switchtime > 0.5)
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && switchtime > 0.2)
		{
			if (x < 466)
			{
				x += y;
				y -= 0.3f;
				rectangleshape.setPosition(x, v);
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && switchtime > 0.2)
		{
			if (x >56)
			{
				x -= y;
				y += 0.3f;
				rectangleshape.setPosition(x, v);
			}
			switchtime = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down) && switchtime > 0.2)
		{
			rectangleshape.setPosition(x, v);
			if (v < 640)
			{
				v += 40.5f;
				v -= 0.2f;

				if (v > 400)
					v -= 0.1f;
			}
			switchtime = 0;
		}
		window.clear();
		window.draw(bg);
		window.draw(rectangleshape);
		window.draw(Grid);
		window.display();
	}
}
