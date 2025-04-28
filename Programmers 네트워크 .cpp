#include<iostream>
#include<vector>
using namespace std;

vector<bool> visited;

void DFS(int node, vector<vector<int>>& edges) {
    visited[node] = true;
    for (size_t i = 0; i < edges[node].size(); i++) {
        if (edges[node][i] && visited[i] == false) {
            DFS(i, edges);
        }
    }
}

void init(vector<bool>& visited) {
    fill(visited.begin(), visited.end(), false);
}

int solution(int n, vector<vector<int>> computers) {
    int NETWORKING = 0;
    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, computers);
            NETWORKING++;
        }
    }
    return NETWORKING;
}

int main() {
    cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} }) << endl; // 2
    init(visited);
    cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} }) << endl; // 1
    return 0;
}
