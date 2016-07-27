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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX - 10;
const int MAX_N = 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

template <typename T>
inline T sqr(T a) { return a * a;};

int N = 5;
int maze[MAX_N][MAX_N], pre[2 * MAX_N];
Pii que[2 * MAX_N];

void pnt_way(int k) {
	if (k != 0) 
		pnt_way(pre[k]);
	printf("(%d, %d)\n", que[k].first, que[k].second);
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> maze[i][j];
	int head = 0, tail = 1;
	que[head] = make_pair(0, 0);
	while (head < tail) {
		int x = que[head].first, y =  que[head].second;
		if (x == N - 1 && y == N - 1) {
			pnt_way(head);
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (0 <= xx && xx < N && 0 <= yy && yy < N && maze[xx][yy] == 0) {
				que[tail] = make_pair(xx, yy);
				maze[xx][yy] = 1;
				pre[tail++] = head;
			}
		}
		++head;
	}
	return 0;
}