#include <stdio.h>

struct MyTime {
    int hour, min, sec, msec;
};

MyTime readTime(const char* msg = "시간") {
    MyTime t;
    printf("%s (시 분 초 밀리초 입력): ", msg);
    scanf("%d %d %d %d", &t.hour, &t.min, &t.sec, &t.msec);
    return t;
}

void printTime(MyTime t, const char* msg = "시간") {
    printf("%s %02d:%02d:%02d:%03d\n", msg, t.hour, t.min, t.sec, t.msec);
}

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime t3;

    t3.msec = t1.msec + t2.msec;
    t3.sec = t1.sec + t2.sec + t3.msec / 1000;
    t3.msec %= 1000;

    t3.min = t1.min + t2.min + t3.sec / 60;
    t3.sec %= 60;

    t3.hour = t1.hour + t2.hour + t3.min / 60;
    t3.min %= 60;

    return t3;
}

int main() {
    MyTime t1, t2, t3;

    t1 = readTime("t1 입력");
    t2 = readTime("t2 입력");

    t3 = addTime(t1, t2);

    printTime(t1, "t1 =");
    printTime(t2, "t2 =");
    printTime(t3, "t1+t2 =");

    return 0;
}