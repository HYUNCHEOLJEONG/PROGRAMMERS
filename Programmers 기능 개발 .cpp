#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;
//v1 93 30 95 v2 1 30 5 
void solution(vector<int>v1, vector<int>v2){
	vector<int>vt;
	int n = v1.size();
	vector<int>remain(n, 0);
	// 7 3 9
	//95 30 93
	for (size_t i = 0; i < n; i++) {
		remain[i] = ceil((100.0 - v1[i]) / v2[i]);
	}
	int count = 0;
	int mx_day = remain[0];
	for (int i = 0; i < n; i++) {
		if (remain[i] <= mx_day) {
			count++;
		}
		else {
			vt.push_back(count);
			count = 1;
			mx_day = remain[i];
		}
	}
	if (count > 0 && vt.empty() || vt.back() != count) {
		vt.push_back(count);  // 마지막 카운트를 추가
	}
	cout << "[";
	for (auto it = vt.begin();it< vt.end();++it) {
		cout << *it;
		if (it < vt.end() - 1) {
			cout << ",";
		}
	}
	cout << "]";

}
int main() {
	string progress;
	string temp;
	cin >> progress;
	vector<int>vt;
	//93 30 55
	progress.erase(remove(progress.begin(), progress.end(), '['), progress.end());
	progress.erase(remove(progress.begin(), progress.end(), ']'), progress.end());
	replace(progress.begin(), progress.end(),',', ' ');
	stringstream ss(progress);
	while (getline(ss, temp, ' ')) {
		vt.push_back(stoi(temp));
	}
	string speeds;
	cin >> speeds;
	string temp2;
	vector<int>vt2;
	//1 30 5
	speeds.erase(remove(speeds.begin(), speeds.end(), '['), speeds.end());
	speeds.erase(remove(speeds.begin(), speeds.end(), ']'), speeds.end());
	replace(speeds.begin(), speeds.end(), ',', ' ');
	stringstream ss2(speeds);
	while (getline(ss2, temp2, ' ')) {
		vt2.push_back(stoi(temp2));
	}
	solution(vt, vt2);
	return 0;
}