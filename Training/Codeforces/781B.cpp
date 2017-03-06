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
const int MAX_V = 2e3 + 10;

string s1, s2;
int N;
set<string> flag, ban;
vector<string> ans;


int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i  = 0; i < N; i++) {
        cin >> s1 >> s2;
        string a = s1.substr(0, 3);
        string b = s1.substr(0, 2) + s2[0];
        if (flag.count(b)) {
            if (ban.count(a) || flag.count(a)) 
                return printf("NO\n"), 0;
            ans.push_back(a);
            flag.insert(a); ban.insert(a);
        } else {
            ans.push_back(b);
            flag.insert(b);
            ban.insert(a);
        }
    }
    printf("YES\n");
    for (auto s : ans)
        cout << s << "\n";
    return 0;
}