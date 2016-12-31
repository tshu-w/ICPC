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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};
int prime[MAX_N];
bool is_prime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    return p;
}
int main(int argc, char const *argv[])
{
	int n, p;
	p = seive(MAX_N);
	while (~scanf("%d", &n) && n) {
		int ans = 0;
		int s = 0, t = 0, sum = 0;
		for(;;) {
			while (t < p && sum < n)
				sum += prime[t++];
			if (t == p) break;
			if (sum == n) ++ans;
			sum -= prime[s++];
		}
		// for (int i = 0; i < p && prime[i] <= n; ++i) {
		// 	int sum = 0;
		// 	for (int j = i; j < p && sum <= n; sum += prime[j], ++j)
		// 		if (sum == n) 
		// 			++ans;
		// }
		printf("%d\n", ans);
	}
	return 0;
}