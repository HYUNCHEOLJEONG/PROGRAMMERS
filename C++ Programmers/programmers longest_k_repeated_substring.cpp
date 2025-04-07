#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀적으로 [start, end) 구간에서 문제를 해결하는 함수
int longestSubstring(const string& s, int start, int end, int k) {
    // 구간 길이가 k보다 작으면 조건을 만족하는 부분 문자열을 만들 수 없음
    if (end - start < k) return 0;

    // 구간 내 각 문자 빈도수 계산
    vector<int> freq(26, 0);
    for (int i = start; i < end; i++) {
        freq[s[i] - 'a']++;
    }

    // 구간 내에서 K번 미만 등장하는 문자가 있으면 해당 문자를 기준으로 분할
    for (int i = start; i < end; i++) {
        if (freq[s[i] - 'a'] < k) {
            int j = i + 1;
            // 연속해서 K 미만인 문자들은 건너뜀
            while (j < end && freq[s[j] - 'a'] < k) {
                j++;
            }
            // 왼쪽과 오른쪽 구간 중 최대값을 반환
            return max(longestSubstring(s, start, i, k), longestSubstring(s, j, end, k));
        }
    }
    // 모든 문자가 K번 이상 등장하면 구간 전체가 조건 만족
    return end - start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    cout << longestSubstring(s, 0, s.size(), k) << "\n";



    return 0;
}