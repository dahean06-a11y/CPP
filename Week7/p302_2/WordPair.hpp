#ifndef MYDIC_H
#define MYDIC_H

#include <string>
using namespace std;

#define MAXWORDS 100

// 단어 쌍 구조체
struct WordPair {
    string eng;
    string kor;
};

// MyDic 클래스 선언
class MyDic {
    WordPair word[MAXWORDS];
    int nwords;

public:
    MyDic(); // 생성자

    void add(string eng, string kor);
    void load(string filename);
    void store(string filename);
    void print();
    string getEng(int id);
    string getKor(int id);
};

#endif