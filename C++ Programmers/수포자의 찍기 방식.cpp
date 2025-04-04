#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//백터에 패턴 파악
vector<int>FirstPattern = { 1,2,3,4,5 };
vector<int>SecondPattern = { 2,1,2,3,2,4,2,5 };
vector<int>ThirdPattern = { 3,3,1,1,2,2,4,4,5,5 };
vector<int>solution(vector<int>comein) {
	vector<int>score_insert;//push하여 return 할 벡터
	vector<int>just_score(3);//점수를 저장할 벡터
	for (size_t i = 0; i < comein.size(); i++) {
		if (comein[i] == FirstPattern[i % FirstPattern.size()]) {
			just_score[0]++;
		}
		if (comein[i] == SecondPattern[i % SecondPattern.size()]) {
			just_score[1]++;
		}
		if (comein[i] == ThirdPattern[i % ThirdPattern.size()]) {
			just_score[2]++;
		}
	}
	int max_score = *max_element(just_score.begin(), just_score.end());// just_score 배열에서 최고 점수 찾기
	for (int i = 0; i < 3; i++) {
		if (just_score[i] == max_score) {
			score_insert.push_back(i + 1);
		}
	}
	return score_insert
		;
}
int main() {
	vector<int>vt = { 1,2,3,4,5 };
	vector<int>vt2 = { 1,3,2,4,2 };
	vector<int>number1 = solution(vt); // 입력값으로 solution함수 값 찾기
	vector<int>number2 = solution(vt2);// 입력값으로 solution함수 값 찾기
	cout << "[";
	for (auto it = number1.begin(); it < number1.end(); ++it) {
		cout << *it;
		if (it != number1.end() - 1) {
			cout << ",";
		}
	}
	cout << "]";
	cout << endl;
}