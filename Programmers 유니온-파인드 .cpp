#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> rankData;

int find(int X) {
	if (parent[X] == X) {
		return X;
	}
	parent[X] = find(parent[X]);
	return parent[X];
}

void Union(int x, int y) {
	int root1 = find(x);
	int root2 = find(y);
	if (root1 != root2) {
		if (rankData[root1] < rankData[root2]) {
			parent[root1] = root2;
		}
		else if (rankData[root1] > rankData[root2]) {
			parent[root2] = root1;
		}
		else {
			parent[root2] = root1;
			rankData[root1]++;
		}
	}
}

vector<string> solution(vector<vector<string>>& operations) {
	vector<string> result;
	int n = operations.size();
	parent.resize(n);
	rankData.resize(n, 0);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (size_t i = 0; i < operations.size(); i++) {
		if (operations[i][0][0] == 'u') {
			int a = stoi(operations[i][1]);
			int b = stoi(operations[i][2]);
			Union(a, b);
		}
		else if (operations[i][0][0] == 'f') {
			int a = stoi(operations[i][1]);
			int b = stoi(operations[i][2]);
			if (find(a) == find(b)) {
				result.push_back("true");
			}
			else {
				result.push_back("false");
			}
		}
	}
	return result;
}

int main() {
	vector<vector<string>> operations;
	vector<string> result;
	string union_find;
	int K, num1, num2;

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> union_find >> num1 >> num2;
		operations.push_back({ union_find, to_string(num1), to_string(num2) });
	}

	result = solution(operations);

	for (auto& res : result) {
		cout << res << "\n";
	}
    return 0;
}
