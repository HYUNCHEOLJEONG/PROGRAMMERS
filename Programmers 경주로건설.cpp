#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

int dx[] = { -1,1,0,0 }; // L, R, U, D
int dy[] = { 0,0,-1,1 }; // L, R, U, D

typedef struct Point {
	int y, x;
	Point(int y1, int x1) : y(y1), x(x1) {};
	Point move(int dir) {
		return Point(y + dy[dir], x + dx[dir]);
	}
}Point;

vector<vector<vector<int>>> dist;
int MAX = numeric_limits<int>::max();

int solution(vector<vector<int>> board) {

	int X_MAX = board[0].size();
	int Y_MAX = board.size();

	dist.assign(Y_MAX, vector<vector<int>>(X_MAX, vector<int>(4, MAX)));
	// assgin 초기화 및 크기 조절 할당
	// resize 크기 할당

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
	// pair ->2쌍
	// tuple -> 3쌍 이상


	for (int i = 0; i < 4; i++) {
		Point next = Point(0, 0).move(i); // 실제로 시발점에서 모든방향 이동
		
		int ny = next.y;
		int nx = next.x;
		if (ny >= 0 && ny < Y_MAX && nx >= 0 && nx < X_MAX && board[ny][nx] == 0) {
			dist[ny][nx][i] = 100; // 3차원 백터 dist[행][열][방향]
			pq.push({ 100, ny, nx, i }); // 우선순위 큐 {비용,y,x,방향}
		}
	}

	while (!pq.empty()) {
		auto [cost, y, x, dir] = pq.top(); // 집합 구성{비용,y좌표,x좌표,이동할 방향]
		pq.pop();

		for (int i = 0; i < 4; i++) {

			Point next = Point(y, x).move(i);
			int next_Y = next.y;
			int next_X = next.x;

			if (0 > next_Y || next_Y >= Y_MAX || 0 > next_X || next_X >= X_MAX)
				continue;
			if (board[next_Y][next_X] == 1)
				continue;

			int new_cost = cost + ((dir == i) ? 100 : 600);
			if (dist[next_Y][next_X][i] > new_cost) {
				dist[next_Y][next_X][i] = new_cost;
				pq.push({ new_cost, next_Y, next_X, i });
			}
		}
	}

	int answer = MAX;
	for (int i = 0; i < 4; i++) {
		answer = min(answer, dist[Y_MAX - 1][X_MAX - 1][i]);
	}
	return answer;
}

void init() {
	dist.clear();
}

int main() {
	cout << solution({
		{0,0,0},
		{0,0,0},
		{0,0,0}
		}) << endl;

	init();

	cout << solution({
		{0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1},
		{0,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,0},
		{1,0,0,0,0,0,0,0}
		}) << endl;

	init();

	cout << solution({
		{0,0,1,0},
		{0,0,0,0},
		{0,1,0,1},
		{1,0,0,0}
		}) << endl;

	init();

	cout << solution({
		{0,0,0,0,0,0},
		{0,1,1,1,1,0},
		{0,0,1,0,0,0},
		{1,0,0,1,0,1},
		{0,1,0,0,0,1},
		{0,0,0,0,0,0}
		}) << endl;

	return 0;
}
