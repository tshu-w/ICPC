// written at 15:59 on 09 Mar 2018
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2e5 + 10;

string s;
int n, k;
vector<int> v[maxn];
stack<int> z, o;

int main() {
    IOS;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == '0') {
            if (o.size() == 0) {
                v[k].push_back(i);
                z.push(k);
                k++;
            } else {
                int tmp = o.top(); o.pop();
                v[tmp].push_back(i);
                z.push(tmp);
            }
        } else {
            if (z.size() == 0) {
                cout << -1 << endl;
                return 0;
            } else {
                int tmp = z.top(); z.pop();
                v[tmp].push_back(i);
                o.push(tmp);
            }
        }
    if (o.size()) {
        cout << -1 << endl;
        return 0;
    }
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << v[i].size();
        for (auto x : v[i]) cout << " " << x + 1;
        cout << endl;
    }
    return 0;
}
