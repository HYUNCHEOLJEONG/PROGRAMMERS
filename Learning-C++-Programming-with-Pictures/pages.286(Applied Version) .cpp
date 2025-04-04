#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string chr;
    vector<string> vt;

    // 문자열 입력 받기
    getline(cin, chr);
    vt.push_back(chr);

    // 벡터의 첫 번째 요소(문자열)의 반복자를 사용하여 문자 변경
    for (auto it = vt[0].begin(); it != vt[0].end(); it++) {
        if (*it == 'h') {
            *it = 'H';
        }
        if (*it == 'e') {
            *it = 'E';
        }
        if (*it == 'i') {
            *it = 'I';
        }
        if (*it == 'o') {
            *it = 'O';
        }
        if (*it == 'w') {
            *it = 'W';
        }
        if (*it == 'r') {
            *it = 'R';
        }
        if (*it == 'd') {
            *it = 'D';
        }
    }

    // 변경된 문자열 출력
    for (const string& p : vt) {
        cout << p;
    }

    return 0;
}