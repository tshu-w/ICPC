#include <bits/stdc++.h>

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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;


const int ST_SIZE = 1 << 18;

int N, M, l, r, k, A[MAX_N], nums[MAX_N];
vector<int> data[ST_SIZE];

void init(int k, int l, int r) {
	if (l + 1 == r)
		data[k].push_back(A[l]);
	else {
		int lch = 2 * k + 1, rch = 2 * k + 2;
		init(lch, l, (l + r) / 2);
		init(rch, (l + r) / 2, r);
		data[k].resize(r - l);
		merge(data[lch].begin(), data[lch].end(), data[rch].begin(), data[rch].end(), data[k].begin());
	}
}

int query(int a, int b, int x, int k, int l, int r) {
	if (b <= l || r <= a)
		return 0;
	else 
		if (a <= l && r <= b) 
			return upper_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
		else 
			return query(a, b, x, 2 * k + 1, l, (l + r) / 2) + query(a, b, x, 2 * k + 2, (l + r) / 2, r);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	init(0, 0, N);

	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &l, &r, &k); --l;
		int lb = -1, ub = N - 1;
		while (lb + 1 < ub) {
			int mid = (lb + ub) / 2;
			if (query(l, r, nums[mid], 0, 0, N) >= k) ub = mid;
			else lb = mid;
		}
		printf("%d\n", nums[ub]);
	}

	return 0;
}


// const int B = 1000;

// int N, M, l, r, k;
// int A[MAX_N], nums[MAX_N];
// vector<int> bucket[MAX_N / B];

// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d", &N, &M);
// 	for (int i = 0; i < N; ++i) {
// 		scanf("%d", A + i);
// 		bucket[i / B].push_back(A[i]);
// 		nums[i] = A[i];
// 	}
// 	sort(nums, nums + N);
// 	for (int i = 0; i < N / B; ++i)
// 		sort(bucket[i].begin(), bucket[i].end());
// 	for (int i = 0; i < M; ++i) {
// 		scanf("%d%d%d", &l, &r, &k); --l;

// 		int lb = -1, ub = N - 1;
// 		while (lb + 1 < ub) {
// 			int mid = (lb + ub) / 2;
// 			int x = nums[mid];
// 			int tl = l, tr = r, c = 0;

// 			while (tl < tr && tl % B != 0) if (A[tl++] <= x) ++c;
// 			while (tl < tr && tr % B != 0) if (A[--tr] <= x) ++c;

// 			while (tl < tr) {
// 				int b = tl / B;
// 				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
// 				tl += B;
// 			}

// 			if (c >= k) ub = mid;
// 			else lb = mid;
// 		}

// 		printf("%d\n", nums[ub]);
// 	}

// 	return 0;
// }