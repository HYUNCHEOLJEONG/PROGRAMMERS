#include <iostream>
#include <vector>
#include <stack>
bool visited[30][30];
using namespace std;
int solution(vector<vector<int>>vt, vector<int>v1) {
    stack<int>stacks;
    for (int num : v1) {
        int pos = 0;
        while (pos < vt.size() && vt[pos][num - 1] == 0) {
            pos++;
        }
        if (visited[pos][num - 1] == false && pos < vt.size() && vt[pos][num - 1] != 0) {
            stacks.push(vt[pos][num - 1]);
            visited[pos][num - 1] = true;
            vt[pos][num - 1] = 0;
        }
    }
    stack<int>st;
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

    return 0;
}