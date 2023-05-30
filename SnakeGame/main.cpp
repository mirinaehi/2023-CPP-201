﻿#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()

#include <stdio.h>

using namespace sf;

#define DIR_UP			0
#define DIR_DOWN		1
#define DIR_RIGHT		2
#define DIR_LEFT		3

class Snake {
public:
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;		// 그래픽
};


class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};


int main(void)
{
	const int WIDTH = 1000;
	const int HEIGHT = 800;
		
	int block = 40; // 한 칸을 40으로
	const int w = WIDTH / block;
	const int h = HEIGHT / block;
	

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	// 1초에 60번의 작업이 이루어 지도록 frame 조절
	// 컴퓨터 사양이 달라도 똑같은 속도로 처리함
	window.setFramerateLimit(20);

	srand(time(NULL));

	Snake snake;
	snake.dir_ = DIR_DOWN;
	snake.x_ = 3;
	snake.y_ = 3;
	snake.sprite_.setPosition(snake.x_ * block, snake.y_ * block);
	snake.sprite_.setSize(Vector2f(block, block));
	snake.sprite_.setFillColor(Color::Green);

	Apple apple;
	apple.x_ = rand() % w;
	apple.y_ = rand() % h;
	apple.sprite_.setPosition(apple.x_*block, apple.y_*block);
	apple.sprite_.setSize(Vector2f(block, block));
	apple.sprite_.setFillColor(Color::Red);

	while(window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}

		// input
		// 네 개의 방향키가 중복으로 input되면 안됨
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.dir_ = DIR_UP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.dir_ = DIR_DOWN;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.dir_ = DIR_RIGHT;
		}
			
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.dir_ = DIR_LEFT;
		}
			
		// update
		
		if (snake.dir_ == DIR_UP) {
			snake.y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.y_++;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.x_++;
		}
		else if (snake.dir_ == DIR_LEFT) {
			snake.x_--;
		}
		snake.sprite_.setPosition(snake.x_ * block, snake.y_ * block);
		


		// 뱀이 사과를 먹으면
		if (snake.x_ == apple.x_ && snake.y_ == apple.y_)
		{
			apple.x_ = rand() % w;
			apple.y_ = rand() % h;
			apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
		}

		// render
		window.clear();

		window.draw(snake.sprite_);
		window.draw(apple.sprite_);	// 뱀과 사과가 겹칠경우 사과가 위에 나옴

		window.display();
	}

	return 0;
}