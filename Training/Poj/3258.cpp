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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};
int L, N, M, a;
vector<int> v;

bool find(int d) {
	int last = 0;
	for (int i = 1; i < N - M; ++i) {
		int crt = last + 1;
		while (crt < N && v[crt] - v[last] < d) {
			++crt;
		}
		if (crt == N) return false;
		last = crt;
	}
	return true;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &L, &N, &M);
    v.push_back(0);
    for (int i = 0; i < N; ++i)
        scanf("%d", &a), v.push_back(a);
    v.push_back(L);
    ++N; ++N;
    sort(v.begin(), v.end());
    int l = 0, r = L + 1;
    while (l + 1 < r) {
    	int mid = l + (r - l) / 2;
    	if (find(mid)) l = mid;
    	else r = mid;
    }
    printf("%d\n", l);
    return 0;
}