#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char* name;
    static int count;   // 객체 개수 관리용 정적 변수

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 문자열을 받는 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else {
            name = nullptr;
        }

        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 객체 개수 출력 함수
    static void printCount() {
        cout << "현재 객체 수 : " << count << endl;
    }

    // 출력용 함수
    void print() {
        if (name != nullptr)
            cout << "name : " << name << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() {
    Sample::printCount();

    Sample a("sample");
    a.print();
    Sample::printCount();

    Sample b(a);
    b.print();
    Sample::printCount();

    return 0;
}