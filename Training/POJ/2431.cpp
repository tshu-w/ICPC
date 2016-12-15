#include <bits/stdc++.h>

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
const int INF = INT_MAX;
const int MAX_N = 1e4 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, L, P;
Pii A[MAX_N];

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
		scanf("%d%d", &A[i].first, &A[i].second);

	cin >> L >> P;
	for (int i = 0; i < N; ++i)
		A[i].first = L - A[i].first;

	sort(A, A + N);

	priority_queue<int> heap;
	heap.push(P);
	
	int dis, index, cnt;
	dis = index = cnt = 0;
	while (dis < L && !heap.empty()) {
		dis += heap.top();
		heap.pop();
		++cnt;
		while (index < N && A[index].first <= dis) 
			heap.push(A[index++].second);
	}
	if (dis < L) 
		cout << -1 << endl;
	else
		cout << cnt - 1 << endl;
	return 0;
}