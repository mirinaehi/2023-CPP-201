#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 합시다
struct Student {
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
};


int main(void)
{
	// (struct Student)자료형(C++에서는 Student만 써도 됩니다)
	struct Student stu1;
	stu1.name = "박남길";
	stu1.hakbun = 2100;
	stu1.age = 18;
	stu1.sex = 0;
	stu1.department = "뉴미디어소프트웨어";

	cout << "이름: " << stu1.name << endl;
	cout << "학번: " << stu1.hakbun << endl;
	cout << "나이: " << stu1.age << endl;
	cout << "성별(0)남자, (1)여자: " << stu1.sex<< endl;
	cout << "학과: " << stu1.department << endl;
	return 0;
}