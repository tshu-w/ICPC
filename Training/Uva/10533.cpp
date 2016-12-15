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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int sum[MAX_N];
int prime[MAX_N];
bool isPrime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (isPrime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
        }
    return p;
}

int main(int argc, char const *argv[])
{
	memset(sum, 0, sizeof sum);
	seive(MAX_N);
	for (int i = 1; i < MAX_N; ++i) {
		if (isPrime[i]) {
			int t = 0, k = i;
			while (k) { t += k % 10; k /= 10;}
			sum[i] = sum[i - 1] + (isPrime[t]? 1 : 0);
		}
		else sum[i] = sum[i - 1];
	}
	int a, b, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}
	return 0;
}