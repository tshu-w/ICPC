// written at 14:24 on 29 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

class SymmetryDetection
{
public:
    string detect(vector <string> board) {
        int n = board.size();
        int m = board[0].size();
        int type = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m / 2; j++)
                if (board[i][j] != board[i][m - j - 1]) flag = false;
        if (flag) type++;

        flag = true;
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n / 2; i++)
                if (board[i][j] != board[n - i - 1][j]) flag = false;

        if (flag) type += 2;

        if (type == 3) return "Both";
        if (type == 2) return "Vertically symmetric";
        if (type == 1) return "Horizontally symmetric";
        return "Neither";
    }
};

int main(void)
{

    return 0;
}
