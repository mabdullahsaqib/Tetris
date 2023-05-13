#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
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
	std::string player;

public:
	Well();
	void Board(RenderWindow& window);
	void CheckForMatch(RenderWindow& window, int& lvl, float& levelspeed);
	void ScoreKeeper(RenderWindow& window, int match, int& lvl, float& levelspeed);
	void Draw(RenderWindow& window, RectangleShape& Grid);
	void Player(RenderWindow& window, Event& e);
	void GameOver(RenderWindow& window);
	void HighScore(RenderWindow& window);
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
	level = 1;
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
	bool name = 0;

	while (window.isOpen())
	{
		Event e;
		deltatime = clock.restart().asSeconds();
		switchtime += deltatime;
		elaspedtime += deltatime;

		if (name == 0)
		{
			Player(window, e);
			name = 1;
			Sleep(100);
		}

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
				GameOver(window);
				Sleep(2000);
				HighScore(window);
				while (Keyboard::isKeyPressed(Keyboard::Key::Enter) == 0);
				window.close();
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
	Border.setFillColor(Color(210, 210, 210));
	for (int i = 0, y = 90.0f; i < 4; i++, y+=200.0f)
	{
		if (i == 0)
		{
			Border.setSize(Vector2f(280.0f, 80.0f));
			Border.setPosition(550.0f, y);
		}
		else
		{
			Border.setSize(Vector2f(150.0f, 60.0f));
			Border.setPosition(600.0f, y);
		}
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
		levelspeed -= 0.1 * levelspeed;
		if (level == 8)
		{
			level = 1;
			levelspeed = 1.0;
		}
	}
	Text Level("Level# " + std::to_string(level), font, 25);
	Level.setPosition(620.0f, 300.0f);
	Level.setFillColor(Color::Black);

	Text PlayerName("Player: " + player, font, 25);
	if (player.length() > 12)
	{
		PlayerName.setPosition(560.0f, 110.0f);
	}
	else
	{
		PlayerName.setPosition(600.0f, 110.0f);
	}
	PlayerName.setFillColor(Color::Black);

	//std::cout << "Score = " << score << "  || Lines Completed = " << linescounter << "  || Level  = " << level << "  || Player Name  = " << player << "\r";

	window.draw(PlayerName);
	window.draw(Level);
	window.draw(Score);
	window.draw(Lines);
}

void Well::Player(RenderWindow& window, Event& e)
{
	RectangleShape Border;
	Border.setSize(Vector2f(470.0f, 220.0f));
	Border.setPosition(Vector2f(190.0f, 555.0f));
	Border.setFillColor(Color(150, 113, 248));

	Texture BackGround;
	BackGround.loadFromFile("Textures/Tetris.jpeg");
	Sprite bg;
	bg.setScale(2.7,3.6);
	bg.setPosition(0,245);
	bg.setTexture(BackGround);
	bg.setColor(Color(150, 150, 200));

	Texture Tetris;
	Tetris.loadFromFile("Textures/Tetris_2.jpeg");
	Sprite title;
	title.setScale(4.6, 3.8);
	title.setPosition(0, 15);
	title.setTexture(Tetris);
	title.setColor(Color(120,120,170));
	
	Font font;
	font.loadFromFile("Fonts/Lobster_1.3.otf");

	Text NameBox("ENTER YOUR NAME", font, 50);
	NameBox.setPosition(220.0f, 575.0f);
	NameBox.setFillColor(Color::White);

	RectangleShape TextBox;
	TextBox.setSize(Vector2f(300.0f, 80.0f));
	TextBox.setPosition(Vector2f(260.0f, 655.0f));
	TextBox.setFillColor(Color(40, 40, 40));

	Text input("", font, 30);
	input.setPosition(300.0f, 675.0f);
	input.setFillColor(Color::White);

	int i = 0;
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

				if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace) && player.length() >= 0)
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
		if (Keyboard::isKeyPressed(Keyboard::Key::Enter) && player.length() > 1)
			break;
		window.clear();
		window.draw(title);
		window.draw(bg);
		window.draw(Border);
		window.draw(TextBox);
		window.draw(NameBox);
		window.draw(input);
		window.display();
	}
}

void Well::GameOver(RenderWindow& window)
{
	Texture Gameover;
	Gameover.loadFromFile("Textures/Gameover.jpeg");
	Sprite end;
	end.setScale(3, 3);
	end.setPosition(50, 100);
	end.setTexture(Gameover);
	end.setColor(Color(200, 200, 200));

	Font font;
	font.loadFromFile("Fonts/Lobster_1.3.otf");

	Text YourScore("YOUR SCORE : " + std::to_string(score), font, 70);
	YourScore.setPosition(170.0f, 500.0f);
	YourScore.setFillColor(Color(200,200,200));

	Texture DinoSaur;
	DinoSaur.loadFromFile("Textures/Ending.jpeg");
	Sprite dino;
	dino.setScale(1, 1);
	dino.setPosition(500, 620);
	dino.setTexture(DinoSaur);

	window.clear();
	window.draw(end);
	window.draw(YourScore);
	window.draw(dino);
	window.display();
}

void Well::HighScore(RenderWindow& window)
{
	std::string Names[5];
	int Scores[5];
	std::ifstream in("HighScore.txt");
	
	for (int i = 0; i < 5; i++)
	{
		in >> Names[i];
		in >> Scores[i];
	}

	int max_index = 0;
	bool flag = 0;
	for (int i = 0; i < 5 && flag == 0 ; i++)
	{
		if (score >= Scores[i])
		{
			max_index = i;
			flag = 1;
		}
		if (flag == 0)
			max_index = 5;
	}

	std::ofstream out("HighScore.txt");

	for (int i = 0, j =0; i < 5; i++)
	{
		if (i != max_index)
		{
			out << Names[j] << std::endl << Scores[j] << std::endl;
			j++;
		}
		else
		{
			out << player << score << std::endl;
		}
	}
	out.close();

	Font font;
	font.loadFromFile("Fonts/Lobster_1.3.otf");

	Texture LeaderBoard;
	LeaderBoard.loadFromFile("Textures/Leaderboard_bg.jpg");
	Sprite bg;
	bg.setScale(2.3, 1.4);
	bg.setPosition(-10, 0);
	bg.setTexture(LeaderBoard);
	bg.setColor(Color(120, 120, 120));

	Text Leaderboard("LEADERBOARD", font, 50);
	Leaderboard.setPosition(260,30);
	Leaderboard.setFillColor(Color::Cyan);
	Leaderboard.setOutlineThickness(1);
	Leaderboard.setOutlineColor(Color::White);
	Leaderboard.setLetterSpacing(1);

	Text Name_Header("Players",font,40);
	Name_Header.setPosition(220, 130);
	Name_Header.setFillColor(Color::Cyan);
	Text Score_Header("Scores",font,40);
	Score_Header.setPosition(520, 130);
	Score_Header.setFillColor(Color::Cyan);

	Text Name[5];
	Text Score[5];

	for (int i = 0, j=0; i < 5; i++)
	{
		if (i != max_index)
		{
			Name[i].setString(Names[j]);
			Score[i].setString(std::to_string(Scores[j]));
			j++;
		}
		else
		{
			Name[i].setString(player);
			Score[i].setString(std::to_string(score));
		}
	}

	for (int i = 0,y=230; i < 5; i++, y+=60)
	{
		Name[i].setFont(font);
		Score[i].setFont(font);
		Name[i].setCharacterSize(30);
		Score[i].setCharacterSize(30);
		Name[i].setPosition(230,y);
		Score[i].setPosition(530,y);

	}

	window.clear();
	window.draw(bg);
	window.draw(Leaderboard);
	window.draw(Name_Header);
	window.draw(Score_Header);
	for (int i = 0; i < 5; i++)
	{
		window.draw(Name[i]);
		window.draw(Score[i]);
	}
	window.display();
}