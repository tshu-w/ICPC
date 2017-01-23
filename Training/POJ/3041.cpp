// written at 14:45 on 20 Jan 2017 
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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
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
const int MAX_V = 1e3 + 10;

vector<int> G[MAX_V];
bool used[MAX_V];
int match[MAX_V];
int V, N, K;

void add_edge(int v, int u) {
	G[v].push_back(u); G[u].push_back(v);
}
bool dfs(int v) {
	used[v] = true;
	rep(i, 0, G[v].size()) {
		int u = G[v][i], w = match[u];
		if (w < 0 || (!used[w] && dfs(w))) {
			match[v] = u; match[u] = v;
			return true;
		}
	}
	return false;
}
int bipatite_match() {
	int res = 0;
	memset(match, -1, sizeof match);
	rep(i, 0, V) if (match[i] < 0) {
		memset(used, false, sizeof used);
		if (dfs(i)) ++res;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);
	rep(i, 0, K) {
		int a, b;
		scanf("%d%d", &a, &b); --a, --b;
		add_edge(a, b + N);
	}
	V = 2 * N;
	printf("%d\n", bipatite_match());
	return 0;
}