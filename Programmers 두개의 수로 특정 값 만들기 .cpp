#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;
bool solution(vector<int>v1, int a) {
	int target = a;
	int vector_size = v1.size();
	unordered_map<int, int>maps;
	for (int index = 0; index < vector_size; index++) {
		maps[v1[index]] = index;
	}
	for (int index = 0; index < vector_size; index++) {
		int complex = target - v1[index];
		if (maps.count(complex)&&maps[complex]!=index) {
			return true;
		}
	}
	return false;
}
int main() {
	string arr1;
	cin >> arr1;
	vector<int>vt1(arr1.size());
	arr1.erase(remove(arr1.begin(), arr1.end(), '['), arr1.end());
	arr1.erase(remove(arr1.begin(), arr1.end(), ']'), arr1.end());
	replace(arr1.begin(), arr1.end(), ',', ' ');
	stringstream ss1(arr1);
	string temp1;
	while (getline(ss1, temp1, ' ')) {
		vt1.push_back(stoi(temp1));
	}
	int number;
	cin >> number;
	cout << (solution(vt1, number) ? "true":"false");

	return 0;
}