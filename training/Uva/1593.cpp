// written at 15:26 on 09 May 2017
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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef pair<int, int > Pii;

const int MAX_N = 200 + 10;
const int MAX_L = 1000 + 10;

string s, ss, buf;
vector<string> dic[MAX_L];
int loc[MAX_N];

int main(void) {
    int i = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        int j = 0;
        while (ss >> buf) {
            dic[i].push_back(buf);
            loc[j] = max(loc[j], (int)dic[i][j].length());
            j++;
        }
        i++;
    }
    for (int ii = 0; ii < i; ii++) {
        for (int jj = 0; jj < (int)dic[ii].size(); jj++) {
            cout << dic[ii][jj];
            if (jj + 1 != (int)dic[ii].size())
                for (int k = 0; k <= loc[jj] - (int)dic[ii][jj].size(); k++)
                    cout << " ";
        }
        cout << endl;
    }
    return 0;
}
