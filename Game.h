#pragma once
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include"Well.h"
//using namespace sf;

class Game
{
private:
	Well well;
public:
	Game(RenderWindow& window);
};

Game::Game(RenderWindow& window)
{
	Font font;
	font.loadFromFile("Fonts/Lobster_1.3.otf");

	RectangleShape Border;
	Border.setSize(Vector2f(520.0f, 250.0f));
	Border.setPosition(Vector2f(170.0f, 280.0f));
	Border.setFillColor(Color(210, 210, 210));

	std::string player;
	Text input("print bitch",font,30);
	input.setPosition(200.0f, 300.0f);
	input.setFillColor(Color::Red);

	int i = 0;
	//well.Board(window);
	Event e;
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::TextEntered:

				if (e.text.unicode == '\b' && player.length() > 0)
				{
					player = player.substr(0, player.length() - 1);
					input.setString(player);
					i--;
				}
				else if (e.text.unicode < 128)
				{
					player += e.text.unicode;
					input.setString(player);
					i++;
				}
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Enter) && player.length() > 5)
			window.close();
		window.clear();
		window.draw(Border);
		window.draw(input);
		window.display();
	}
	std::ofstream out;
	out.open("HighScore.txt");
	out << player;
	out.close();
}
