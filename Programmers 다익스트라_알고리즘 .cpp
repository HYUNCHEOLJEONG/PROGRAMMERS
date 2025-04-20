#include<iostream>
#include<vector>
#include<limits>
using namespace std;
const int INF = numeric_limits<int>::max();
vector<int>solution(int start, vector<vector<int>> edges, int& numNodes) {
    vector<int>results; //반환될 벡터
    results.resize(numNodes, INF);
    vector<bool>visited;
    //방문 초기화
    visited.resize(numNodes, false);
 
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, INF));
    //그래프 초기화
 
    results[start] = 0;
    //그래프 값 대입
    for (const auto& pair : edges) {
        int Start = pair[0];
        int Arrive = pair[1];
        int weight = pair[2];
        graph[Start][Arrive] = weight;
    }
    for (size_t i = 0; i <numNodes; i++) {
        int minNodes = -1;
        int minNodes_value = INF;
        for (size_t j = 0; j<numNodes; j++) {
            if (visited[j] == false && results[j] < minNodes_value) {
                minNodes = j;
                minNodes_value = results[j];
            }
        }
        if (minNodes == -1) {
            break;
        }
        visited[minNodes] = true;
        for (size_t j = 0; j <numNodes; j++) {
            if (!visited[j] && graph[minNodes][j] != INF &&
                results[j] > results[minNodes] + graph[minNodes][j]) {
                results[j] = results[minNodes] + graph[minNodes][j];
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
    }
    cout << endl;


    for (const auto& pair2 : p2) {
        if (pair2 != INF) {
            cout << pair2 << " ";
        }
    }

    return 0;
}
