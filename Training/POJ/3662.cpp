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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge
{
	int from, to, dis;	
};

int N, P, K, a, b, l, dist[MAX_N];
vector<edge> G[MAX_N];

bool C(int L) {
	priority_queue<Pii, vector<Pii>, greater<Pii> > que;
	fill(dist, dist + N, INF);
	dist[0] = 0; que.push(Pii(0, 0));
	while (que.size()) {
		Pii p = que.top(); que.pop();
		int v = p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (dist[e.to] > dist[v] + ((e.dis > L) ? 1 : 0)) {
				dist[e.to] = dist[v] + ((e.dis > L) ? 1 : 0);
				que.push(Pii(dist[e.to], e.to));
			}
		}
	}
	return dist[N - 1] <= K;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &N, &P, &K);
	for (int i = 0; i < P; ++i) {
		scanf("%d%d%d", &a, &b, &l);
		--a; --b;
		G[a].push_back(edge{a, b, l});
		G[b].push_back(edge{b, a, l});
	}
	int lb = -1, ub = 1000001;
	while (ub - lb > 1) {
		int mid = (ub - lb) / 2 + lb;
		if (C(mid)) ub = mid;
		else lb = mid;
	}
	if (ub > 1000000) printf("-1\n");
	else printf("%d\n", ub);
	return 0;
}