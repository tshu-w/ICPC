// written at 22:08 on 31 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;


ll k, cnt[20];
string n;

int main() {
    IOS;
    cin >> k >> n;
    ll sum = 0;
    for (auto ch : n) {
        sum += ch - '0';
        cnt[ch - '0']++;
    }
    if (sum >= k) cout << "0\n";
    else {
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (sum + (9 - i) * cnt[i] >= k) {
                ans += (k - sum) / (9 - i) + ((k - sum) % (9 - i)? 1 : 0); break;
            }
            sum += (9 - i) * cnt[i];
            ans += cnt[i];
        }
        cout << ans << endl;
    }
    return 0;
}
