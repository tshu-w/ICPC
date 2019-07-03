// written at 22:00 on 23 Dec 2017
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

int n, tot, st[30], kn, ff[30];
string ch, wd;

int main() {
    IOS;
    cin >> n;
    for (int i = 0; i < 26; i++) st[i] = 1;
    for (int i = 0; i < n; i++) {
        cin >> ch >> wd;
        if (ch == ".") {
            for (auto c : wd) st[c - 'a'] = 0; // X
        } else if (ch == "!") {
            if (kn) tot++;
            memset(ff, 0, sizeof ff);
            for (auto c : wd) ff[c - 'a'] = 1; // maybe
            for (int i = 0; i < 26; i++)
                if (st[i] == 1 && ff[i] == 1) st[i] = 1;
                else st[i] = 0;
        } else {
            if (kn && i + 1 != n) tot++;
            st[wd[0] - 'a'] = 0;
        }
        if (!kn) {
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                if (st[i] == 1) cnt++;
            if (cnt == 1) kn = 1;
        }
    }
    cout << tot << endl;
    return 0;
}
