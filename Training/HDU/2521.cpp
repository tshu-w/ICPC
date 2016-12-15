#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 5000 + 10;

const double PI = acos(-1.0);
int count(int n) {
    vector<int> res;
    res.resize(0);
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
	        if (i != n / i) res.push_back(n / i);
	    }
    }
    return (int)res.size();
}
int main(int argc, char const *argv[])
{
	int t, a, b, g[MAX_N], gm[MAX_N];
	for (int i = 1; i < MAX_N; ++i) {
		g[i] = count(i);
		if (i == 1) 
			gm[i] = 0;
		else
			gm[i] = max(gm[i - 1], g[i - 1]);
	}
	// for (int i = 1; i < MAX_N; ++i)
	// 	if (gm[i] < g[i])
	// 	printf("%d %d\n", i, g[i]);
	// printf("\n");
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		int ans = 0;
		for (int i = a; i <= b; ++i)
			if (g[i] > g[ans]) 
				ans = i;
		printf("%d\n", ans);
	}
	return 0;
}