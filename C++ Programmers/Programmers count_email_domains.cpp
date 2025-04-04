#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    int N;
    cin >> N;  // 이메일의 개수 입력
    string email_ID;
    map<string, int> domain_count;  // 도메인별 카운트를 저장할 map

    // 사용자 이메일 입력받기
    for (int i = 0; i < N; i++) {
        cin >> email_ID;

        // 이메일에서 도메인 추출
        size_t pos = email_ID.find('@');  // '@'의 위치 찾기
        if (pos != string::npos) {
            string domain = email_ID.substr(pos + 1);  // '@' 이후의 문자열(도메인)
            domain_count[domain]++;  // 해당 도메인의 카운트 증가
        }
    }

    // "example.com"과 "gmail.com"이 포함된 이메일 수 카운트
    int MAX_count_email = 0;
    int MAX_count2_email = 0;

    for (const auto& pair : domain_count) {
        if (pair.first.find("example") != string::npos) {  // "example"이 포함된 도메인
            MAX_count_email += pair.second;
        }
        if (pair.first.find("gmail") != string::npos) {  // "gmail"이 포함된 도메인
            MAX_count2_email += pair.second;
        }
    }

    // 결과 출력
    cout << "example.com: " << MAX_count_email << endl;
    cout << "gmail.com: " << MAX_count2_email << endl;

    return 0;
}