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

int N, M, ans;
ll F, sum;
pair<Pii, int> score[MAX_N], aid[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d%lld", &N, &M, &F);
	N /= 2;
	for (int i = 0; i < M; ++i)
		scanf("%d%d", &score[i].first.first, &score[i].first.second);
	sort(score, score + M);
	for (int i = 0; i < M; ++i)
		score[i].second = i;
	for (int i = 0; i < M; ++i) {
		aid[i].first.first = score[i].first.second;
		aid[i].first.second = score[i].first.first;
		aid[i].second = score[i].second;
	}
	sort(aid, aid + M);
	int lb = 0, ub = M, l, r;
	while (ub - lb > 1) {
		int mid = (ub - lb) / 2 + lb;
		l = r = 0;
		sum = score[mid].first.second;
		for (int i = 0; i < M; ++i) {
			if (l < N && aid[i].second < score[mid].second && sum + aid[i].first.first <= F) {
				++l;
				sum += aid[i].first.first;
			}
			if (r < N && aid[i].second > score[mid].second && sum + aid[i].first.first <= F) {
				++r;
				sum += aid[i].first.first;
			}
		}
		if (l < N && r < N || sum > F) {
			ans = -1;
			break;
		} else if (l < N) {
			lb = mid;
		} else if (r < N) {
			ub = mid;
		} else {
			ans = score[mid].first.first;
			lb = mid;
		}
	}
	printf("%d\n", ans);
	return 0;
}