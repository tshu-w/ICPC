// written at 08:09 on 6 Mar 2017 
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
const ll LLINF = LLONG_MAX;
const int MAX_V = 1e3 + 10;

string s1, s2, name[MAX_V][2];
int N, ans[MAX_V];
map<string, int> mp, vis;


int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i  = 0; i < N; i++) {
        cin >> s1 >> s2;
        name[i][0] = s1.substr(0, 3);
        name[i][1] = s1.substr(0, 2) + s2[0];
        mp[name[i][0]]++;
    }
    bool flag;
    do {
        flag = false;
        for (int i = 0; i < N; i++) 
            if (mp[name[i][ans[i]]] > 1 || (vis[name[i][ans[i]]] && ans[i] == 0)) {
                if (ans[i] == 1) continue;
                flag = true;
                mp[name[i][0]]--; mp[name[i][1]]++;
                ans[i] = 1;
                vis[name[i][0]] = 1;
            }
    } while (flag);
    for (int i = 0; i < N; i++)
        if (mp[name[i][ans[i]]] > 1)
            return printf("NO\n"), 0;
    printf("YES\n");
    for (int i = 0; i < N; i++)
        cout << name[i][ans[i]] << "\n";
    return 0;
}