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

void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    pt->msec = t1.msec + t2.msec;
    pt->sec = t1.sec + t2.sec + pt->msec / 1000;
    pt->msec %= 1000;

    pt->min = t1.min + t2.min + pt->sec / 60;
    pt->sec %= 60;

    pt->hour = t1.hour + t2.hour + pt->min / 60;
    pt->min %= 60;
}

int main() {
    MyTime t1, t2, t3;

    t1 = readTime("t1 입력");
    t2 = readTime("t2 입력");

    addTime(t1, t2, &t3);

    printTime(t1, "t1 =");
    printTime(t2, "t2 =");
    printTime(t3, "t1+t2 =");

    return 0;
}