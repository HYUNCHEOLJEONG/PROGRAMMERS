// 배열을 통한 트리 순차 검색
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 전위 순회: 루트 → 왼쪽 → 오른쪽
string preorder(vector<int> v, int index) {
    if (index < v.size()) {
        string temp = to_string(v[index]);             // 루트 방문
        string left = preorder(v, index * 2 + 1);       // 왼쪽 방문
        string right = preorder(v, index * 2 + 2);      // 오른쪽 방문
        if (!left.empty()) temp += " " + left;
        if (!right.empty()) temp += " " + right;
        return temp;
    }
    return "";
}

// 중위 순회: 왼쪽 → 루트 → 오른쪽
string midorder(vector<int> v, int index) {
    if (index < v.size()) {
        string left = midorder(v, index * 2 + 1);       // 왼쪽 방문
        string temp = to_string(v[index]);              // 루트 방문
        string right = midorder(v, index * 2 + 2);      // 오른쪽 방문
        if (!left.empty()) temp = left + " " + temp;
        if (!right.empty()) temp += " " + right;
        return temp;
    }
    return "";
}

// 후위 순회: 왼쪽 → 오른쪽 → 루트
string lastorder(vector<int> v, int index) {
    if (index < v.size()) {
        string left = lastorder(v, index * 2 + 1);      // 왼쪽 방문
        string right = lastorder(v, index * 2 + 2);     // 오른쪽 방문
        string temp = to_string(v[index]);              // 루트 방문
        if (!left.empty()) temp = left + " " + temp;
        if (!right.empty()) temp = right + " " + temp;
        return temp;
    }
    return "";
}

// 솔루션 함수
vector<string> solution(vector<int> v) {
    vector<string> answer;
    answer.push_back(preorder(v, 0));   // 전위 순회 결과
    answer.push_back(midorder(v, 0));   // 중위 순회 결과
    answer.push_back(lastorder(v, 0));  // 후위 순회 결과
    return answer;
}

int main() {
    vector<string> answer = solution({ 1, 2, 3, 4, 5, 6, 7 });
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}