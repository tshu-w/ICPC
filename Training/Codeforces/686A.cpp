#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
    ll x, a;
    int d = 0, n;
    char ch;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> a;
        if (ch == '+') {
            x += a;
        }
        else {
            if (x >= a) {
                x -= a;
            }
            else {
                ++d;
            }
        }
    }
    cout << x << ' ' << d << endl;
    return 0;
}