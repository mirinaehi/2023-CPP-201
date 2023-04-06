#include <iostream>
#include <string>

using namespace std;

struct Actor {
	string name;
	string dialog;
};

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 합시다
// class는 디폴트가 private (struct는 디폴트가 public)
class Student {
public:
	// 생성자(constructor) : 객체가 생성될 때 호출되는 함수
	Student()
	{
		hakbun = 2100;
		name = "박남길";
		age = 18;
		sex = 0;
		department = "뉴미디어소프트웨어";
	}

	Student(string _name, int _hakbun, int _age, int _sex, string _department)
	{
		hakbun = _hakbun;
		name = _name;
		age = _age;
		sex = _sex;
		department = _department;
	}

	// class는 멤버변수를 가질 수 있다
	void print(void)
	{
		cout << "이름: " << name << endl;
		cout << "학번: " << hakbun << endl;
		cout << "나이: " << age << endl;
		cout << "성별(0)남자, (1)여자: " << sex << endl;
		cout << "학과: " << department << endl;
	}

private:
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
	Student stu1 = Student("뉴진스", 2100, 18, 1, "뉴미디어소프트웨어");
	// stu1.print();

	struct Actor KYLee;
	KYLee.name = "이경영";
	KYLee.dialog = "진행시켜";

	struct Actor* ptr = &KYLee;

	// ptr->name, (*ptr).name 같은 결과
	cout << "이름 : " << ptr->name << endl;
	cout << "대사 : " << (*ptr).dialog << endl;

	return 0;
}