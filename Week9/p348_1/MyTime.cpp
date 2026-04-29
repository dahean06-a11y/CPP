#include "MyTime.hpp"
#include <iostream>
using namespace std;

// 생성자
MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), minute(m), second(s), millisecond(ms)
{
}

// 초 입력 생성자
MyTime::MyTime(double duration) {
    convert(duration);
}

// 초 → 시/분/초/밀리초 변환
void MyTime::convert(double duration) {
    int total_ms = (int)(duration * 1000);

    hour = total_ms / (1000 * 60 * 60);
    total_ms %= (1000 * 60 * 60);

    minute = total_ms / (1000 * 60);
    total_ms %= (1000 * 60);

    second = total_ms / 1000;
    millisecond = total_ms % 1000;
}

// 🔥 시간 더하기
MyTime MyTime::operator+(const MyTime& t) const {
    int total1 = ((hour * 60 + minute) * 60 + second) * 1000 + millisecond;
    int total2 = ((t.hour * 60 + t.minute) * 60 + t.second) * 1000 + t.millisecond;

    int sum = total1 + total2;

    MyTime result;
    result.convert(sum / 1000.0);

    return result;
}

// 출력
void MyTime::print() const {
    cout << hour << "h "
         << minute << "m "
         << second << "s "
         << millisecond << "ms" << endl;
}

int main() {
    double d1, d2;

    cout << "첫 번째 시간(초)을 입력하세요: ";
    cin >> d1;

    cout << "두 번째 시간(초)을 입력하세요: ";
    cin >> d2;

    MyTime t1(d1);  // 초로 생성
    MyTime t2(d2);

    MyTime result = t1 + t2;  // 🔥 더하기

    cout << "\n첫 번째 시간: ";
    t1.print();

    cout << "두 번째 시간: ";
    t2.print();

    cout << "합계 시간: ";
    result.print();

    return 0;
}