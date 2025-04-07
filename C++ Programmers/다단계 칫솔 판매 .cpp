#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, string> Search;
    unordered_map<string, int> Seller;

    // 추천인 관계 세팅 + 이익 초기화
    for (size_t i = 0; i < enroll.size(); i++) {
        Search[enroll[i]] = referral[i];
    } 
    for (const auto& name : enroll) {
        Seller[name] = 0;
    }
    // 이익 분배
    for (size_t i = 0; i < seller.size(); i++) {
        string current = seller[i];
        int profit = amount[i] * 100;
        while (current != "-" && profit > 0) {
            int give = profit / 10;
            Seller[current] += profit - give;
            if (Search.find(current)!= Search.end()) {
                current = Search[current];
            }
            else {
                break;
            }
            profit = give;
        }
    }

    // enroll 순서대로 결과 출력
    for (const string& name : enroll) {
        cout << Seller[name] << " ";
    }
    cout << endl;
}

int main() {
    solution(
        { "john","mary","edward","sam","emily","jaimie","tod","young" },
        { "-","-","mary","edward","mary","mary","jaimie","edward" },
        { "young","john","tod","emily","mary" },
        { 12,4,2,5,10 }
    );

    solution(
        { "john","mary","edward","sam","emily","jaimie","tod","young" },
        { "-","-","mary","edward","mary","mary","jaimie","edward" },
        { "sam","emily","jaimie","edward" },
        { 2,3,5,4 }
    );

    return 0;
}