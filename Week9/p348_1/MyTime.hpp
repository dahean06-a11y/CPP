#ifndef MYTIME_HPP
#define MYTIME_HPP

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0);
    MyTime(double duration);

    void convert(double duration);
    void print() const;

    // 🔥 더하기 연산자
    MyTime operator+(const MyTime& t) const;
};

#endif