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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const int maxp = 310;
const int maxn = 2000 + 10;
bool vis[maxn + 10];
int prime[maxp], pcnt = 0;

void Init()
{
    int m = sqrt(maxn + 0.5);
    for(int i = 2; i <= m; i++) if(!vis[i])
        for(int j = i * i; j <= maxn; j += i) vis[j] = true;
    for(int i = 2; i <= maxn; i++) if(!vis[i]) prime[pcnt++] = i;
}

typedef long long Matrix[maxn][6];

Matrix A;

int rnk(Matrix A, int m, int n)
{
    int i = 0, j = 0, len = n / 64;
    while(i < m && j < n)
    {
        int r = i, k;
        for(k = r; k < m; k++) if(A[k][j/64] & (1LL<<(j%64))) { r = k; break; }
        if(k < m)
        {
            if(r != i) for(int k = 0; k <= len; k++) swap(A[r][k], A[i][k]);
            for(int k = i+1; k < m; k++) if(A[k][j/64] & (1LL<<(j%64)))
                for(int l = 0; l <= len; l++) A[k][l] ^= A[i][l];
            i++;
        }
        j++;
    }
    return i;
}
ll mod_pow(ll x, ll n, ll mod) { 
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{

    Init();
    int T, tt = 0;
    scanf("%d", &T);
    while(T--)
    {
    	printf( "Case #%d:\n", ++tt );
        memset(A, 0, sizeof(A));
        int n, M = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            long long x;
            scanf("%lld", &x);
            for(int j = 0; j < pcnt; j++) while(x % prime[j] == 0)
            {
                M = max(M, j);
                x /= prime[j];
                A[j][i/64] ^= (1LL << (i%64) );
            }
        }
        int r = rnk(A, M+1, n);
        printf("%lld\n", (mod_pow(2, n - r, MOD) - 1 + MOD) % MOD);
    }

    return 0;
}