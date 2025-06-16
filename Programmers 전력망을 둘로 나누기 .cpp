#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int DFS(int node,int parent,vector<vector<int>>&graph) {
	
	int cnt = 1;

	for (auto child : graph[node]) {
		if (child != parent) {
			cnt += DFS(child, node, graph);
		}
	}
	return cnt;
}

int solution(int n,vector<vector<int>>wires){
	vector<vector<int>>graph(n + 1);

	for (const auto& pair : wires) {
		int a = pair[0];
		int b = pair[1];
		//양방향으로 그래프 완성
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int difference = numeric_limits<int> ::max();
	for (const auto& pair : wires) {
		int a = pair[0];
		int b = pair[1];

		graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
		graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

		
		int cnt_a = DFS(a, b, graph);
		int cnt_b = n - cnt_a;

		difference = min(difference, abs(cnt_a - cnt_b));
        
		graph[a].push_back(b);
		graph[b].push_back(a);

	}
	return difference;
}

int main() {

	int result = solution(9, {
		{1,3},{2,3},{3,4},
		{4,5},{4,6},{4,7},
		{7,8},{7,9}
		});

	cout << result << endl;



	int result2 = solution( 4,{
		{1,2},{2,3},{3,4}
    } );
	cout << result2<<endl;

	int result3 = solution(7, {
		{1,2},{2,7},{3,7},
		{3,4},{4,5},{6,7}
	});

	cout << result3<<endl;



	return 0;
}