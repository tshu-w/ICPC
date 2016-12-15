#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename "test"
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
const int MAX_N = 6e5 + 10;

// int rprim[50]= {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,
// 20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400};
// int nprim[50]= {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,
// 120,128,144,160,168,180,192,200,216};

int N, K, num[MAX_N];
char name[MAX_N][15];

int cnt[MAX_N];
int rprim[100], rn = 0, nprim[100];

void rprime(int N) {
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < N; ++i) 
		for (int j = i; j < N; j += i)
			++cnt[j];
	int res = 0;
	for (int i = 0; i < N; ++i)
		if (res < cnt[i]) {
			rprim[rn] = i;
			nprim[rn++] = cnt[i];
			res = max(cnt[i], res);
		}
}

int bit[MAX_N + 1];
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}
void add(int i, int x) {
	while (i <= N) {
		bit[i] += x;
		i += i & -i;
	}
}

int out(int k) {
	int lb = 0, ub = N;
	while (lb + 1 < ub) {
		int mid = (lb + ub) / 2;
		if (sum(mid) < k) lb = mid;
		else ub = mid;
	}
	return ub - 1;
}

int main(int argc, char const *argv[])
{
	rprime(MAX_N);
	while (~scanf("%d%d", &N, &K)) {
		memset(bit, 0, sizeof bit);
		for (int i = 0; i < N; ++i) {
			scanf("%s%d", name[i], num + i);
			add(i + 1, 1);
		}
		int it = 0, n = N;
		while(rprim[it] <= N) it++; --it;
		for (int i = 0; i < rprim[it]; ++i) {
			int p = out(K);
			add(p + 1, -1);
			if (i + 1 == rprim[it]) {
				printf("%s %d\n", name[p], nprim[it]);
				break;
			}
			--n;
			if (num[p] < 0)
				K = (K + num[p] % n + n) % n;
			else K = (K - 1 + num[p] % n + 2 * n) % n;
			if (!K) K = n;
		}
	}
	return 0;
}