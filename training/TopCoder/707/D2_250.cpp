// written at 19:16 on 9 Feb 2017 
#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Cross
{
public:
    string exist(vector <string> board) {
        bool flag = false;
        rep(i, 1, board.size())
            rep(j, 1, board[i].size()) if (board[i][j] == '#') {
                bool f = true;
                rep(d, 0, 4) {
                    int x = i + dx[d], y = j + dy[d];
                    if (board[x][y] != '#') f = false;
                }
                flag |= f;
            }
        return flag? "Exist" : "Does not exist";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}