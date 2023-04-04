﻿#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 합시다
// class는 디폴트가 private (struct는 디폴트가 public)
class Student {
public:
	string name;
	
	// 성능때문에 hakbun을 문자열로 하지 않음
	// 일반적으로 문자열은 정수데이터보다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자수 만큼 반복하여 비교해야함
	int hakbun;
	int age;
	// 가독성과 유지보수를 위해 열거형(enum)으로 하는것을 추천
	// 0: 남자, 1: 여자
	int sex;
	string department;

	// 생성자(constructor) : 객체가 생성될 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다
	// Student(){}

	// class는 멤버변수를 가질 수 있다
	void print(void)
	{
		cout << "이름: " << name << endl;
		cout << "학번: " << hakbun << endl;
		cout << "나이: " << age << endl;
		cout << "성별(0)남자, (1)여자: " << sex << endl;
		cout << "학과: " << department << endl;
	}
};


int main(void)
{	
	Student stu1;
	stu1.name = "박남길";
	stu1.hakbun = 2100;
	stu1.age = 18;
	stu1.sex = 0;
	stu1.department = "뉴미디어소프트웨어";

	stu1.print();
	
	return 0;
}