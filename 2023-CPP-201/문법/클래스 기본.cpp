#include <iostream>
#include <string>

using namespace std;

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

	// : 멤버변수 초기화를 하면 const 멤버변수도 초기화 할 수 있다
	Student(string _name, int _hakbun, int _age, int _sex, string _department)
		: name(_name), hakbun(_hakbun), age(_age)
		, sex(_sex), department(_department)
	{
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
	// 정적할당 : 메모리의 크기가 컴파일할 때 결정됨
	// Student stu1 = Student("뉴진스", 2100, 18, 1, "뉴미디어소프트웨어");
	// stu1.print();
	Student stu3[2];
	for (int i = 0; i < 2; i++)
		stu3[i].print();


	// 동적할당 : 메모리의 크기가 실행할 때(runtime) 결정됨. heap영역
	// C++의 동적할당은 반드시 delete로 해제해야 메모리 누수를 막을 수 있음
	// Student* stu2 = new Student("서강준", 3100, 31, 0, "방송연예과");
	// stu2->print();		// 단일객체는 멤버를 ->로 접근
	// delete stu2;
	
	Student* stu4 = new Student[2];
	for (int i = 0; i < 2; i++)
		stu4[i].print();	// 배열의 요소에 해당하는 객체는 멤버를 .으로 접근
	delete[] stu4;

	return 0;
}