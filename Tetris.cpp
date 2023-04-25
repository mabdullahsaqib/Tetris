#include<iostream>
#include<SFML/Graphics.hpp> 
#include"Game.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(840, 820), "TETRIS!!", Style::Titlebar | Style::Resize | Style::Close);
	Game tetris(window);
	
	return 0;
}