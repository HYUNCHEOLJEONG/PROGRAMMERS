#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// 실패율을 정렬하기 위한 비교 함수
bool compare(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second)
        return a.first < b.first;  // 실패율이 같으면 스테이지 번호가 작은 순서대로 정렬
    return a.second > b.second;  // 실패율 내림차순으로 정렬
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;  // 최종 답을 저장할 벡터
    vector<int> challenger(N + 2, 0);  // 각 스테이지에 도달한 도전자의 수
    vector<int> fail(N + 2, 0);  // 각 스테이지에서 실패한 도전자의 수

    // 각 도전자의 스테이지 정보 분석
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++) {
            challenger[j]++;  // 각 스테이지에 도달한 인원수 증가
        }
        fail[stages[i]]++;  // 특정 스테이지에서 실패한 인원수 증가
    }

    // 실패율을 저장할 벡터
    vector<pair<int, float>> failRatio(N);

    // 실패율 계산
    for (int i = 0; i < N; i++) {
        failRatio[i].first = i + 1;  // 스테이지 번호

        if (challenger[i + 1] == 0)
            failRatio[i].second = 0;  // 도전자가 없으면 실패율은 0
        else
            failRatio[i].second = (float)fail[i + 1] / challenger[i + 1];  // 실패율 계산
    }

    // 실패율에 맞게 정렬
    sort(failRatio.begin(), failRatio.end(), compare);

    // 최종 답에 스테이지 번호를 저장
    for (int i = 0; i < N; i++) {
        answer.push_back(failRatio[i].first);
    }

    return answer;
}

// 결과 출력 함수
void print(vector<int> vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    // 테스트
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3})); // 예상 출력: 3 4 2 1 5
    print(solution(4, {4, 4, 4, 4, 4}));         // 예상 출력: 4 1 2 3
    return 0;
}