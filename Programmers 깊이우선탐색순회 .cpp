#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool visited[256] = { false };
bool first = true;
void DFS(unordered_map<char,vector<char>>& maps,char& start) {
	if (visited[start]) { return; }
	else {
		visited[start] = true;

		if (!first) {
			cout << ",";
		}
		cout << start;
		first = false;

		for (char next : maps[start]) {
			DFS(maps, next);
			
		}
	}

}

void solution(vector<pair<char,char>>v,char start) {
	vector<char>result;
	for (size_t i = 0; i <256; i++) {
		visited[i] = false;
	}
	unordered_map<char, vector<char>> maps;
	//정렬되지않은 맵 키값 벡터의 문자 
	//중복 -> "value 값을 벡터의 배열로 치환"
	for (size_t i = 0; i < v.size(); i++) {
		maps[v[i].first].push_back(v[i].second);
	}
	first =true;
	cout << "[";
	DFS(maps, start);
	cout << "]";
	cout << endl;

}



int main() {


	solution({ {'A','B'},{'B','C'},{'C','D'}, { 'D','E' }}, {'A'});
	solution({ {'A','B'},{'A','C'},{'B','D'},{'B','E'},{'E','F'} },{'A'});


	return 0;
}