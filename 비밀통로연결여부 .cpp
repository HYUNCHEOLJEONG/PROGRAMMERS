#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool>visited;
vector<vector<int>>tree;
bool answer = false;
void DFS(vector<int>v,int& arrive) {

	for (int i = 0; i < v.size(); i++) {

		int node = v[i];

		for (auto pair : tree[node]) {
			if (visited[pair] == true) {
				continue;
			}
			else {
				if (pair == arrive) {
					answer = true;
					return;
				}
				visited[pair] = true;
				v.push_back({ pair });
				DFS(v,arrive);
				v.pop_back();
				visited[pair] = false;

			}
		}
	}



}
int solution(vector<pair<int,int>>&v,int &N,int& start,int &arrive) {
	tree.resize(N+1);
	visited.resize(N + 1, false);
	//Connection Deside Tree
	for (auto& pair : v) {
		tree[pair.first].push_back(pair.second);
		tree[pair.second].push_back(pair.first);
	}
	visited[start] = true;
	DFS({start},arrive);

	return answer;

}
int main() {
	//N: 방의 개수
	//M: 비밀 통로
	//S: A의 출발
	//T :B가 있는곳
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<pair<int,int>>v;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cout << (solution(v, N, S, T) ? "true" : "false");

	return 0;
}