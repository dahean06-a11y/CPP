#include <iostream>
#include <fstream>
#include "WordPair.hpp"

using namespace std;

// 생성자
MyDic::MyDic() {
    nwords = 0;
}

// 단어 추가
void MyDic::add(string eng, string kor) {
    if (nwords >= MAXWORDS) {
        cout << "단어장이 가득 찼습니다.\n";
        return;
    }
    word[nwords].eng = eng;
    word[nwords].kor = kor;
    nwords++;
}

// 파일에서 읽기
void MyDic::load(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "파일을 열 수 없습니다.\n";
        return;
    }

    nwords = 0;
    while (!fin.eof()) {
        string eng, kor;
        fin >> eng;
        if (fin.eof()) break;
        fin >> kor;

        add(eng, kor);
    }

    fin.close();
}

// 파일에 저장
void MyDic::store(string filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "파일을 열 수 없습니다.\n";
        return;
    }

    for (int i = 0; i < nwords; i++) {
        fout << word[i].eng << " " << word[i].kor << endl;
    }

    fout.close();
}

// 출력
void MyDic::print() {
    cout << "===== 단어장 =====\n";
    for (int i = 0; i < nwords; i++) {
        cout << i << ": " << word[i].eng 
             << " -> " << word[i].kor << endl;
    }
}

// 영어 반환
string MyDic::getEng(int id) {
    if (id < 0 || id >= nwords) return "";
    return word[id].eng;
}

// 한글 반환
string MyDic::getKor(int id) {
    if (id < 0 || id >= nwords) return "";
    return word[id].kor;
}

int main() {
    MyDic dic;
    int choice;

    while (true) {
        cout << "\n===== 메뉴 =====\n";
        cout << "1. 단어 추가\n";
        cout << "2. 단어 출력\n";
        cout << "3. 파일 저장\n";
        cout << "4. 파일 불러오기\n";
        cout << "0. 종료\n";
        cout << "선택: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string eng, kor;
            cout << "영어 단어 입력: ";
            cin >> eng;
            cout << "한글 설명 입력: ";
            cin >> kor;

            dic.add(eng, kor);
        }
        else if (choice == 2) {
            dic.print();
        }
        else if (choice == 3) {
            string filename;
            cout << "파일 이름 입력: ";
            cin >> filename;
            dic.store(filename);
        }
        else if (choice == 4) {
            string filename;
            cout << "파일 이름 입력: ";
            cin >> filename;
            dic.load(filename);
        }
        else {
            cout << "잘못된 입력입니다.\n";
        }
    }

    cout << "프로그램 종료\n";
    return 0;
}