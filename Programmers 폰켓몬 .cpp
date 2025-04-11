#include <iostream>
#include <vector>
#include <algorithm> // for shuffle
#include <random>    // for mt19937
#include <chrono>    // for seeding
using namespace std;

pair<int, int> pickTwoDifferentRandom(const vector<int>& v) {
    vector<int> temp = v;

    // 셔플을 위한 랜덤 엔진
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    shuffle(temp.begin(), temp.end(), mt19937(seed));

    // 서로 다른 값 2개 찾기
    for (int i = 0; i < temp.size(); i++) {
        for (int j = i + 1; j < temp.size(); j++) {
            if (temp[i] != temp[j]) {
                return { temp[i], temp[j] }; // 서로 다르면 리턴
            }
        }
    }

    // 실패 시 -1 반환 (같은 값밖에 없을 경우)
    return { -1, -1 };
}

int main() {
    vector<int> v = { 3, 3, 2, 2, 1, 1 };

    auto [a, b] = pickTwoDifferentRandom(v);

    if (a != -1)
        cout << "뽑은 값: " << a << " 와 " << b << endl;
    else
        cout << "서로 다른 값을 뽑을 수 없습니다." << endl;

    return 0;
}
