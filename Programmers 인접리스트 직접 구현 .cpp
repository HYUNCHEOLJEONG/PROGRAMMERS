#include <iostream>
#include <vector>
using namespace std;

struct nodeinfo {
    int W; // 가중치
    int Start_index;
    int Arrive_index;
    int Sum = 0; // 합계
};

vector<vector<nodeinfo>> Node_vector;

// 연결 리스트 구현
void connectlist(int Start_index, int w, int Arrive_index) {
    nodeinfo temp = { w, Start_index, Arrive_index };
    Node_vector[Start_index].push_back(temp);
}

void Node_result() {
    // Sum 계산
    for (int i = 0; i < Node_vector.size(); i++) {
        for (int j = 0; j < Node_vector[i].size(); j++) {
            Node_vector[i][j].Sum += Node_vector[i][j].W;
        }
    }

    // 결과 출력
    for (const auto& pair1 : Node_vector) {
        for (const auto& pair : pair1) {
            cout << "W: " << pair.W << ", Start: " << pair.Start_index
                << ", Arrive: " << pair.Arrive_index << ", Sum: " << pair.Sum << endl;
        }
    }
}

int main() {
    int number;
    cout << "노드 개수를 입력하세요: ";
    cin >> number;

    if (number <= 0) {
        cerr << "노드 개수는 0보다 커야 합니다." << endl;
        return 1;
    }

    Node_vector.resize(number + 1); // Node_vector 크기 초기화

    connectlist(1, 2, 3);
    connectlist(2, 1, 6);
    connectlist(2, 3, 5);
    connectlist(3, 2, 1);
    connectlist(3, 4, 13);
    connectlist(4, 4, 9);
    connectlist(4, 1, 42);

    Node_result();
    return 0;
}
