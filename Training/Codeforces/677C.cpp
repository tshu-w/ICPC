#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 5;
const l MOD = 1e9 + 7;

template <typename T>
inline T sqr(T a) { return a * a;};

int cal(int n) {
    int res = 0;
    while (n) {
        if (n & 1) ++res;
        n /= 2; 
    }
    return pow(3, 6 - res);
}
int main(int argc, char const *argv[])
{
    char ch;
    ll ans = 1;
    map<char, int> m;
    for (int i = 0; i < 10; ++i) m[i + '0'] = i;
    for (int i = 0; i < 26; ++i) m[i + 'A'] = i + 10;
    for (int i = 0; i < 26; ++i) m[i + 'a'] = i + 36;
    m['-'] = 62; m['_'] = 63;
    for (auto & x : m) 
        x.second = cal(x.second);
    while (~scanf("%c", &ch) && m.count(ch)) 
        ans = ans * m[ch] % MOD;
    cout << ans << endl;
    return 0;
}