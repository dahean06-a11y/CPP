#pragma once
#include <iostream>

class MyTime {
private:
    int hour, min, sec, msec;

public:
    // (1) 간략화된 멤버 함수 선언
    void convert(double duration);   // 초 → 시간 변환
    void print();                    // 출력
    MyTime add(MyTime t);            // 객체 더하기
    void reset();                    // 초기화
    void read();                     // 입력
};