#include "MyTime.hpp"
#include <iomanip>  // setfill, setw
using namespace std;

// ===============================
// (1) 멤버 함수 구현 (모두 inline 대신 일반 구현)
// ===============================

// 초 → 시간 변환
void MyTime::convert(double duration) {
    hour = (int)(duration / 3600);
    duration -= hour * 3600;

    min = (int)(duration / 60);
    duration -= min * 60;

    sec = (int)(duration);
    duration -= sec;

    msec = (int)(duration * 1000);
}

// (3) cout + 조작자 사용 출력
void MyTime::print() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << ":"
         << setw(3) << msec << endl;
}

// 시간 더하기 (객체 반환)
MyTime MyTime::add(MyTime t) {
    MyTime result;

    result.msec = msec + t.msec;
    result.sec  = sec + t.sec;
    result.min  = min + t.min;
    result.hour = hour + t.hour;

    // 자리 올림
    if (result.msec >= 1000) {
        result.sec += result.msec / 1000;
        result.msec %= 1000;
    }
    if (result.sec >= 60) {
        result.min += result.sec / 60;
        result.sec %= 60;
    }
    if (result.min >= 60) {
        result.hour += result.min / 60;
        result.min %= 60;
    }

    return result;
}

// 초기화
void MyTime::reset() {
    hour = min = sec = msec = 0;
}

// (4) 입력 함수
void MyTime::read() {
    double duration;
    cout << "초 단위 시간을 입력하세요: ";
    cin >> duration;
    convert(duration);
}

int main() {
    MyTime t1, t2, t3;

    t1.read();
    t2.read();

    t3 = t1.add(t2);

    cout << "더한 결과: ";
    t3.print();

    string cmd;
    cout << "reset 입력 시 초기화: ";
    cin >> cmd;

    if (cmd == "reset") {
        t3.reset();
        cout << "초기화 후: ";
        t3.print();
    }

    return 0;
}