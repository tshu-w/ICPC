//#include <bits/stdc++.h>
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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif	
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

template<typename T> T exgcd(T a, T b, T &x, T &y) { 
    T d = a; 
    if (b) { 
        d = exgcd(b, a % b, y, x); 
        y -= a / b * x; 
    } else { 
        x = 1; y = 0; 
    } 
    return d;
}
template<typename T> T mod_inverse(T a, T m) {
    T x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

int CRT(vector<int> &a, vector<int> &m) {
    int M = 1LL, res = 0;
    for (int i = 0; i < m.size(); ++i)
        M *= m[i];
    for (int i = 0; i < m.size(); ++i) {
        int Mi, Ti;
        Mi = M / m[i]; Ti = mod_inverse(Mi, m[i]);
        res = (res + a[i] * (Mi * Ti) % M) % M;
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<int> m(3);
	m[0] = 23; m[1] = 28; m[2] = 33;
	int p, e, i, d, cs = 0;
	while (~scanf("%d%d%d%d", &p, &e, &i, &d) && (p + 1 || e + 1 || i + 1 || d + 1)) {
		p %= 23;  e %= 28;  i %= 33;
		vector<int> a(3);
		a[0] = p; a[1] = e; a[2] = i;
		int ans = (CRT(a, m) - d + 21252) % 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cs, ans? ans : 21252);
	}
	return 0;
}