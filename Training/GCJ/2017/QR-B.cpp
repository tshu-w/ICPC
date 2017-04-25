// written at 17:11 on 8 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
// #define filename "B-small-attempt0"
#define filename "B-large"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
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
const int MAX_N = 1e5 + 10;

int t;
string n;

bool C(int k) {
    vector<int> v;
    while (k) {
        v.push_back(k % 10);
        k = k / 10;
    }
    for (int i = 0; i + 1 < v.size(); i++)
        if (v[i] < v[i + 1]) return false;
    return true;
}

int main() {
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        // int i;
        // for (i = n; i >= 0; i--)
        //     if (C(i)) break;
        for (int i = n.size() - 1; i < n.size(); i--)
            for (int j = i + 1; j < n.size(); j++)
                if (n[i] > n[j]) {
                    n[i]--;
                    for (int k = i + 1; k < n.size(); k++)
                        n[k] = '9';
                }
        // if (k != -1)
        //     for (int i = k + 1; i < n.size(); i++)
        //         n[i] = '9';
        printf("Case #%d: ", _ + 1);
        int k = 0;
        for (int i = 0; i < n.size(); i++)
            if (n[i] != '0') {
                k = i;
                break;
            }
        cout << n.substr(k) << endl;
    }
    resetfile();
    return 0;
}