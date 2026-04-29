#include "MyTime.hpp"
#include <iostream>
using namespace std;

// 기본 생성자 (초기화 리스트)
MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), minute(m), second(s), millisecond(ms)
{
}

MyTime::MyTime(double duration) {
    int total_ms = (int)(duration * 1000);

    hour = total_ms / (1000 * 60 * 60);
    total_ms %= (1000 * 60 * 60);

    minute = total_ms / (1000 * 60);
    total_ms %= (1000 * 60);

    second = total_ms / 1000;
    millisecond = total_ms % 1000;
}

// 출력 함수
void MyTime::print() const {
    cout << hour << "h "
         << minute << "m "
         << second << "s "
         << millisecond << "ms" << endl;
}

// 🔥 시간 더하기
MyTime MyTime::operator+(const MyTime& t) const {
    int total1 = ((hour * 60 + minute) * 60 + second) * 1000 + millisecond;
    int total2 = ((t.hour * 60 + t.minute) * 60 + t.second) * 1000 + t.millisecond;

    int sum = total1 + total2;

    return MyTime(sum / 1000.0);  // 🔥 다시 생성자 사용
}

int main() {
    double d1, d2;

    cout << "첫 번째 시간(초)을 입력하세요: ";
    cin >> d1;

    cout << "두 번째 시간(초)을 입력하세요: ";
    cin >> d2;

    MyTime t1(d1);
    MyTime t2(d2);

    MyTime result = t1 + t2;

    cout << "\n첫 번째 시간: ";
    t1.print();

    cout << "두 번째 시간: ";
    t2.print();

    cout << "합계 시간: ";
    result.print();

    return 0;
}