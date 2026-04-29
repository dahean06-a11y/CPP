#ifndef MYTIME_HPP
#define MYTIME_HPP

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    // 기본 + 일반 생성자
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0);

    // 🔥 실수형 시간 생성자 (생성자 위임용)
    MyTime(double duration);

    void print() const;

    // 🔥 더하기 연산자
    MyTime operator+(const MyTime& t) const;
};

#endif