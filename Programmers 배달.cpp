#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;
int solution(int& N, vector<vector<int>>road, int& K) {
	vector<vector<pair<int, int>>>graph(N + 1);
	vector<int>dist(N + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	
	//connection list =>graph
	for (const auto& pair : road) {
		int a = pair[0], b = pair[1], c = pair[2];
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	// each other list connection
	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cur_distance = pq.top().first;
		int cur_Node = pq.top().second;
		pq.pop();
		if (cur_distance>dist[cur_Node]) {
			continue;
		}
		for (auto& pair : graph[cur_Node]) {
			int next_Node = pair.first;
			int Weight = pair.second;
			if (dist[next_Node] > dist[cur_Node] + Weight) {
				dist[next_Node] = dist[cur_Node] + Weight;
				pq.push({ dist[next_Node],next_Node });
			}
		}
	}
	//Using answer research dist array

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K) {
			answer++;
		}
	}

	return answer;
}
int main() {
	int N = 5, K = 3;
	cout << solution(N,{ {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},
		{5,4,2}
		},K);

    cout << endl;

	int N2 = 6, K2 = 4;
	cout << solution(N2,{ {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},
		{3,5,3},{5,6,1}
		},K2);


	return 0;
}