// written at 20:24 on 17 Jan 2017
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
const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e2 + 10;
const int MAX_M = 1e2 + 10;
int t, N, M, pre[MAX_M][MAX_N];
bool dp[MAX_M][MAX_N];
string name[MAX_N], sentence[MAX_M], s;

void write(int i, int j) {
    if (!i) return;
    write(i - 1, pre[i][j]);
    if (sentence[i - 1][0] != '?')
        cout << sentence[i - 1] << endl;
    else {
        cout << name[j];
        string s(sentence[i - 1], sentence[i - 1].find(':'), string::npos);
        cout << s << endl;
    }
}
bool in(string s, string S) {
    rep(i, 0, S.size())
        if (!isalnum(S[i])) S[i] = ' ';
    S = S + " ";
    return    S.find(" " + s + " ") != string::npos;
}
void solve() {
    memset(dp, false, sizeof dp);
    memset(pre, -1, sizeof pre);
    rep(i, 0, N) dp[0][i] = true;
    rep(i, 0, M) if (sentence[i][0] == '?') {
        rep(j, 0, N) if (!in(name[j], sentence[i])) {
            rep(k, 0, N) if (k != j && dp[i][k]) {
                dp[i + 1][j] = true;
                pre[i + 1][j] = k;
                break;
            }
        }
    } else {
        int id = -1;
        string s(sentence[i], 0, sentence[i].find(':'));
        rep(j, 0, N) if (s == name[j]) {id = j; break;}
        rep(j, 0, N) if ((j != id || !i) && dp[i][j]) {
            dp[i + 1][id] = true;
            pre[i + 1][id] = j;
            break;
        }
    }
    rep(i, 0, N)
        if (dp[M][i]) {
            write(M, i);
            return;
        }
    cout << "Impossible" << endl;
}

int main(int argc, char const *argv[])
{
    IOS;
    cin >> t;
    rep(i, 0, t) {
        cin >> N; getline(cin, s);
        rep(i, 0, N)
            cin >> name[i];
        cin >> M; getline(cin, s);
        rep(i, 0, M)
            getline(cin, sentence[i]);
        solve();
    }
    return 0;
}