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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, C;
ll F, l[MAX_N], r[MAX_N];
Pii A[MAX_N];
priority_queue<int> q, qq;

int main(int argc, char const *argv[])
{
	scanf("%d%d%lld", &N, &C, &F);
	N /= 2;
	for (int i = 0; i < C; ++i) 
		scanf("%d%d", &A[i].first, &A[i].second);
	sort(A, A + C, greater<Pii>());
	ll sum = 0;
	for (int i = 0; i < C; ++i) {
		l[i] = q.size() == N? sum : INF;
		q.push(A[i].second);
		sum += A[i].second;
		if (q.size() > N) {
			sum -= q.top(); q.pop();
		} 
	}
	sum = 0;
	for (int i = C - 1; i >= 0; --i) {
		r[i] = qq.size() == N? sum : INF;
		qq.push(A[i].second);
		sum += A[i].second;
		if (qq.size() > N) {
			sum -= qq.top(); qq.pop();
		} 
	}
	for (int i = 0; i < C; ++i)
		if (l[i] + r[i] + A[i].second <= F) {
			printf("%d\n", A[i].first);
			return 0;
		}
	printf("-1\n");
	return 0;
}