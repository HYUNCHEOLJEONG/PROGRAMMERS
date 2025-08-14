#include <iostream>
#include <vector>
#include <stack>
bool visited[30][30];
using namespace std;
// vt = borard
// v1 = moves
int solution(vector<vector<int>>vt, vector<int>v1) {
    stack<int>stacks;  // 크레인으로 뽑아낸 인형들을 임시로 담아두는 스택
    //크레인 움직임 반복
    for (int num : v1) {
        int pos = 0;
        while (pos < vt.size() && vt[pos][num - 1] == 0) {
            pos++;
        }
        // v1의 각 숫자마다 pos=0 부터 boar[pos][num-1]를 확인
        // 열(num-1)에서 가장 위에 있는 인형(0이 아닌 값)을 찾기 위해 pos++ 내려감

        //인형을 발견하면
        if (visited[pos][num - 1] == false && pos < vt.size() && vt[pos][num - 1] != 0) {
            stacks.push(vt[pos][num - 1]);
            visited[pos][num - 1] = true;
            vt[pos][num - 1] = 0;
        }
    }
    stack<int>st; // 인형을 담아두는 스택
    int count = 0;
   while(!stacks.empty()) {
        int top = stacks.top();
        stacks.pop();
        if (!st.empty() && st.top() == top) {
            st.pop();
            count += 2;
        }
        else {
            st.push(top);
        }

    }
    return count;
}


int main() {
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };

    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

  cout <<  solution(board, moves);
  // board : 인형이 쌓여있는 판
  // moves :크레인을 움직일 열
  // solution()에 board와 moves를 넘겨 실행

    return 0;
}

/**def solution(board, moves):
    stack_temp = []  # 크레인으로 뽑아낸 인형들을 임시로 담아두는 스택

    # 크레인 움직임 반복
    for num in moves:
        pos = 0
        while pos < len(board) and board[pos][num - 1] == 0:
            pos += 1
        # moves의 각 숫자마다 pos=0부터 board[pos][num-1]를 확인
        # 열(num-1)에서 가장 위에 있는 인형(0이 아닌 값)을 찾기 위해 pos++ 내려감

        # 인형을 발견하면
        if pos < len(board) and board[pos][num - 1] != 0:
            stack_temp.append(board[pos][num - 1])
            board[pos][num - 1] = 0

    stack = []  # 인형을 담아두는 스택
    count = 0

    while stack_temp:
        top = stack_temp.pop()
        if stack and stack[-1] == top:
            stack.pop()
            count += 2
        else:
            stack.append(top)

    return count


if __name__ == "__main__":
    board = [
        [0, 0, 0, 0, 0],
        [0, 0, 1, 0, 3],
        [0, 2, 5, 0, 1],
        [4, 2, 4, 4, 2],
        [3, 5, 1, 3, 1]
    ]

    moves = [1, 5, 3, 5, 1, 2, 1, 4]

    # board : 인형이 쌓여있는 판
    # moves : 크레인을 움직일 열
    # solution()에 board와 moves를 넘겨 실행
    print(solution(board, moves))

 **/