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

template <typename T>
inline T sqr(T a) { return a * a;};

priority_queue<Pii> que;
int main(int argc, char const *argv[])
{
    int n, k, a[MAX_N], ans;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int p;
    for (p = n; p > 0; --p)
        if (a[p - 1] < 100)
            break;
    if (p == 0)
        ans = n * 10;
    else {
        ans = (n - p) * 10;
        for (int i = 0; i < p; ++i) {
            que.push(make_pair(a[i] % 10, a[i]));
            ans += a[i] / 10;
        }
        while (k && !que.empty()) {
            Pii m = que.top();que.pop();
            k -= 10 - m.first;
            m.second += 10 - m.first;
            if (k >= 0) ans++;
            if (m.second != 100)
                que.push(make_pair(0, m.second));
        }
    }
    cout << ans << endl;
    return 0;
}