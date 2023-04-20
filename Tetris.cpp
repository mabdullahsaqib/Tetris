#include<iostream>
#include<SFML/Graphics.hpp> 
#include"Well.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(840, 820), "TETRIS!!", Style::Titlebar | Style::Resize | Style::Close);
	Well well;
	well.Board(window);
	
	return 0;
}