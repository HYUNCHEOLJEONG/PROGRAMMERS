#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[] = { -1,1,0,0 }; // x의 변화량
int dy[] = { 0,0,-1,1 }; // y의 변화량
bool check[100][100];      // 방문 여부 확인 배열

typedef struct Point {
    int x, y;
    Point(int y1, int x1) : y(y1), x(x1) {};
    Point move(int value) {
        return Point(y + dy[value], x + dx[value]);
    }
} Point;

queue<Point> q;

int solution(vector<vector<int>> maps) {
    int width = maps[0].size();
    int height = maps.size();
    int dist[100][100] = { 0 }; // 거리 저장

    // 시작점 방문 처리
    q.push(Point(0, 0));
    check[0][0] = true;
    dist[0][0] = 1; // 시작점 거리 1로 설정

    while (!q.empty()) {
        Point now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point next = now.move(i);
            int nx = next.x;
            int ny = next.y;

            if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                if (!check[ny][nx] && maps[ny][nx] == 1) {
                    q.push(next);
                    check[ny][nx] = true;
                    dist[ny][nx] = dist[now.y][now.x] + 1;
                }
            }
        }
    }

    // 도착점까지 거리 반환, 못 갔으면 -1
    if (dist[height - 1][width - 1] == 0)
        return -1;
    return dist[height - 1][width - 1];
}

int main() {
    int p = solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
    cout << p << '\n'; // 11

    // check 배열 초기화 (중복 호출 대비)
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            check[i][j] = false;

    // 큐 초기화
    while (!q.empty()) q.pop();

    int p2 = solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} });
    cout << p2 << '\n'; // -1 (못 감)

    return 0;
}
