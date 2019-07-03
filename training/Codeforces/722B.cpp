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

template <typename T>
inline T sqr(T a) { return a * a;};
const int MAX_N = 100 + 10;

const char ch[] = {'a', 'e', 'i', 'o', 'u', 'y'};
int n, P[MAX_N];
string s;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> P[i];
    bool flag = true;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int cnt = 0;
        for (int j = 0; j < s.size(); ++j) {
            for (int k = 0; k < 6; ++k)
                if (s[j] == ch[k]) ++cnt;
        }
        if (cnt != P[i]) {flag = false;}
    }
    if (flag)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}