#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()

#include <stdio.h>

using namespace sf;

#define DIR_UP			0
#define DIR_DOWN		1
#define DIR_LEFT		2
#define DIR_RIGHT		3

#define BODY_MAX		20		// 뱀 몸통의 최대길이


const int WIDTH = 1000;
const int HEIGHT = 800;

int block = 40; // 한 칸을 40으로
const int w = WIDTH / block;
const int h = HEIGHT / block;


class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_;		// 그래픽
};

class Snake {
public:
	Snake(int dir, int length, float thickness, int block)
		:dir_(dir), length_(length), thickness_(thickness)
	{
		inner_ = block - thickness_;
	}

	void InitBody(void)
	{
		// TODO : 뱀과 사과가 걸치지 않도록 수정하기
		for (int i = 0; i < BODY_MAX; i++) {
			body_[i].x_ = -100;
			body_[i].y_ = -100;
			body_[i].sprite_.setPosition(body_[i].x_ * block, body_[i].y_ * block);
			body_[i].sprite_.setSize(Vector2f(inner_, inner_));
			body_[i].sprite_.setFillColor(Color::Green);
			// 뱀의 테두리
			body_[i].sprite_.setOutlineColor(Color::Color(0, 128, 0));
			body_[i].sprite_.setOutlineThickness(5);
		}
		body_[0].x_ = 3;
		body_[0].y_ = 3;
	}

	// 현재 사과를 먹고있는 상태인가?
	bool isCollide(Apple* apple)
	{
		return body_[0].x_ == apple->x_ && body_[0].y_ == apple->y_;
	}

	// 몸통(머리 제외)
	void UpdateBody(void)
	{
		for (int i = length_ - 1; i > 0; i--) {
			body_[i].x_ = body_[i - 1].x_;
			body_[i].y_ = body_[i - 1].y_;
		}
	}

	// 머리
	void UpdateHead(void)
	{
		if (dir_ == DIR_UP) {
			body_[0].y_--;
		}
		else if (dir_ == DIR_DOWN) {
			body_[0].y_++;
		}
		else if (dir_ == DIR_RIGHT) {
			body_[0].x_++;
		}
		else if (dir_ == DIR_LEFT) {
			body_[0].x_--;
		}
	}

	void UpdateBoundary(void)
	{
		// 바운더리를 넘었을 때 더이상 벗어나지 않도록
		if (body_[0].x_ < 0)
			body_[0].x_ = 0;
		if (body_[0].x_ >= w)
			body_[0].x_ = w - 1;
		if (body_[0].y_ < 0)
			body_[0].y_ = 0;
		if (body_[0].y_ >= h)
			body_[0].y_ = h - 1;


		for (int i = 0; i < length_; i++) {
			body_[i].sprite_.setPosition(body_[i].x_ * block, body_[i].y_ * block);
		}
	}

	void Render(RenderWindow* window)
	{
		for (int i = 0; i < BODY_MAX; i++) {
			window->draw(body_[i].sprite_);
		}
	}

	int GetDir(void) { return dir_; }
	int GetLength(void) { return length_; }
	float GetThickness(void) { return thickness_; }
	float GetInner(void) { return inner_; }

	void SetDir(int dir) { dir_ = dir; }
	void SetLength(int length) { length_ = length; }
	void SetThickness(float thickness) { thickness_= thickness; }
	void SetInner(float inner) { inner_ = inner; }

	// 길이 1 증가
	void IncLength(void) { length_++; }

private:
	int dir_;
	int length_;
	float thickness_;			// 외피두께
	float inner_;				// 내부두께
	Object body_[BODY_MAX];
};


int main(void)
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	// 1초에 60번의 작업이 이루어 지도록 frame 조절
	// 컴퓨터 사양이 달라도 똑같은 속도로 처리함
	window.setFramerateLimit(20);

	srand(time(NULL));

	Snake snake = Snake(DIR_DOWN, 1, 5.f, block);
	snake.InitBody();
	

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
			snake.SetDir(DIR_UP);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.SetDir(DIR_DOWN);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.SetDir(DIR_RIGHT);
		}
			
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.SetDir(DIR_LEFT);
		}

		// update
		// 뱀이 사과를 먹으면 길이가 늘어짐
		// if (snake.body_[0].x_ == apple.x_ && snake.body_[0].y_ == apple.y_)
		if (snake.isCollide(&apple))
		{
			apple.x_ = rand() % w;
			apple.y_ = rand() % h;
			apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
			if(snake.GetLength() < BODY_MAX)
				snake.IncLength();
		}

		snake.UpdateBody();
		snake.UpdateHead();
		snake.UpdateBoundary();

		// render
		window.clear();

		snake.Render(&window);

		window.draw(apple.sprite_);	// 뱀과 사과가 겹칠경우 사과가 위에 나옴

		window.display();
	}

	return 0;
}