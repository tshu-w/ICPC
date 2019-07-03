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

vector<int> v, v1, v2;
int n, m, flag[10], ans = 0, test[10];

vector<int> trans(int n) {
    vector<int> res;
    if (!n) res.push_back(0);
    while (n) {
        res.push_back(n % 7);
        n /= 7;
    }
    return res;
}
void dfs(int k) {
    if (k == v.size()) {
        for (int i = v1.size() - 1; i >= 0; --i)
            if (test[i] > v1[i]) 
                return;
            else if (test[i] < v1[i]) break;
        for (int i = v.size() - 1; i >= v1.size(); --i)
            if (test[i] > v2[i - v1.size()])
                return;
            else if (test[i] < v2[i - v1.size()]) break;
        // for (int i = 0; i < v.size(); ++i)
            // cout << test[i];
        // cout << endl;
        ++ans;
    }
    else 
        for (int i = 0; i < 7; ++i)
            if (!flag[i]) {
                flag[i] = true;
                test[k] = i;
                dfs(k + 1);
                flag[i] = false;
            }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    --n;--m;
    v1 = trans(n), v2 = trans(m);
    if (v1.size() + v2.size() > 7) {
        cout << 0 << endl;
    }
    else {
        fill(flag, flag + 10, false);
        for (int i = 0; i < v1.size(); ++i)
            v.push_back(v1[i]);
        for (int i = 0; i < v2.size(); ++i)
            v.push_back(v2[i]);
        // for (int i = 0; i < v.size(); ++i)
        //     cout << v[i];
        // cout << endl << endl;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}