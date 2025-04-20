#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int start, vector<vector<int>> edges, int& numNodes) {
    vector<int> results(numNodes, INF);
    vector<vector<pair<int, int>>> graph(numNodes); // 인접 리스트: {to, weight}

    // 그래프 초기화
    for (const auto& e : edges) {
        int from = e[0], to = e[1], weight = e[2];
        graph[from].push_back({ to, weight });
    }

    // 최소힙 우선순위 큐: {거리, 노드}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    results[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 더 짧은 거리로 이미 방문했으면 skip
        if (currDist > results[u]) continue;

        for (const auto& p : graph[u]) {
            int v = p.first;
            int weight = p.second;
            if (results[v] > results[u] + weight) {
                results[v] = results[u] + weight;
                pq.push({ results[v], v });
            }
        }
    }

    return results;
}

int main() {
    int numNodes, numNodes2;
    cin >> numNodes >> numNodes2;

    vector<int> p = solution(0, { {0,1,9},{0,2,3},{1,0,5},{2,1,1} }, numNodes);
    vector<int> p2 = solution(0, { {0,1,1},{1,2,5},{2,3,1} }, numNodes2);

    for (const auto& pair : p) {
        if (pair != INF) {
            cout << pair << " ";
        }
        else {
            cout << "INF ";
        }
    }
    cout << endl;

    for (const auto& pair2 : p2) {
        if (pair2 != INF) {
            cout << pair2 << " ";
        }
        else {
            cout << "INF ";
        }
    }
    cout << endl;

    return 0;
}
