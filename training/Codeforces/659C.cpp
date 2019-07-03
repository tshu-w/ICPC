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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
    int n, m, a;
    vector<int> v, ans;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int p = 1;
    bool flag;
    while (m - p >= 0 && p <= 1e9) {
        if ( upper_bound(v.begin(), v.end(), p) != lower_bound(v.begin(), v.end(), p) + 1) {
            m -= p;
            ans.push_back(p);
        }
        ++p;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}