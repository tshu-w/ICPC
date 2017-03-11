// written at 11:51 on 8 Mar 2017 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector> 
#include <utility>
#include <bitset>
#include <numeric>

using namespace std;

struct Board {
    int state[4][8];
    bool satisfy() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 7; j++)
                if (state[i][j] != (i + 1) * 10 + j + 1) return false;
        return true;
    }
    void debug() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 8; j++) 
                printf("%3d%c", state[i][j], " \n"[j == 7]);
        printf("\n");
    }
};

bool operator< (const Board& lhs, const Board& rhs) {
    return memcmp(&lhs, &rhs, sizeof(Board)) < 0;
}

int board[4][8], t;

void init() {
    memset(board, 0, sizeof board);
    for (int i = 0; i < 4; i++)
        for (int j = 1; j < 8; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] % 10 == 1) {
                int x = board[i][j] / 10 - 1;
                swap(board[i][j], board[x][0]);
            }
        }
}

int solve() {
    queue<pair<Board, int> > que;
    set<Board> st;
    Board s;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            s.state[i][j] = board[i][j];
    que.push(make_pair(s, 0));
    while (que.size()) {
        Board cur = que.front().first;
        int step = que.front().second;
        que.pop();
        // cout << step << endl;
        // cur.debug();
        if (cur.satisfy()) return step;
        step++;
        for (int i = 0; i < 4; i++)
            for (int j = 1; j < 8; j++) if (cur.state[i][j] == 0){
                int dat = cur.state[i][j - 1] + 1;
                for (int ii = 0; ii < 4; ii++)
                    for (int jj = 0; jj < 8; jj++) if (cur.state[ii][jj] == dat) {
                        swap(cur.state[ii][jj], cur.state[i][j]);
                        if (!st.count(cur)) {
                            st.insert(cur);
                            que.push(make_pair(cur, step));
                        }
                        swap(cur.state[ii][jj], cur.state[i][j]);
                    }
            }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        init();
        printf("%d\n", solve());
    }     
    return 0;
}