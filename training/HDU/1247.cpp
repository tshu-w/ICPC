#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

map<string, int> dic;
string s[MAX_N];

int main(int argc, char const *argv[])
{
    int n = 0;
    while (cin >> s[n]) 
        ++dic[s[n++]];
    for (int i = 0; i < n; ++i) {
        int len = s[i].length();
        for (int j = 1; j < len; ++j) {
            string s1 = s[i].substr(0, j);
            if (!dic[s1]) continue;
            s1 = s[i].substr(j);
            if (!dic[s1]) continue;
            cout << s[i] << endl;    
            break;
        }
    }
    return 0;
}