// #include <bits/stdc++.h>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 500000 + 5;

const double PI = acos(-1.0);

int c[MAX_N];
int main(int argc, char const *argv[])
{    
    int n, k;
    vector<int> c;
    scanf("%d%d", &n, &k);
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        c.push_back(x);
    }
    sort(c.begin(), c.end());
    vector<pair<ll, ll> > vp;
    for (int i = 0; i < n; ++i) {
        if ( vp.empty() || c[i] > vp.back().first) {
            vp.push_back(make_pair(c[i], 1));
        } else
            ++vp.back().second;
    }
    int m = vp.size();
    vector<pair<ll, ll> > s1(m), s2(m);
    s1[0].second = vp[0].second;
    for (int i = 1; i < m; ++i) {
        s1[i].second = s1[i - 1].second + vp[i].second;
        s1[i].first = s1[i - 1].first + s1[i - 1].second * (vp[i].first - vp[i - 1].first);
    }
    s2[m - 1].second = vp[m - 1].second;
    for (int i = m - 2; i >= 0; --i) {
        s2[i].second = s2[i + 1].second + vp[i].second;
        s2[i].first = s2[i + 1].first + s2[i + 1].second * (vp[i + 1].first - vp[i].first);
    }
    int l = 0, r = m - 1;
    while (l < m - 1 && s1[l + 1].first < k)
        ++l;
    while (r > 0 && s2[r - 1].first < k)
        --r;
    long long cl = vp[l].first + (k - s1[l].first) / s1[l].second;
    long long cr = vp[r].first - (k - s2[r].first) / s2[r].second;
    if (cl < cr) {
        cout << cr - cl << endl;
    } else {
        if (accumulate(c.begin(), c.end(), 0ll) % n == 0)
            cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}