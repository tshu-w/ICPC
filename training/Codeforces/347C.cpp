#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 100 + 10;

const double PI = acos(-1.0);

int gcd(int a, int b) {
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n, a[MAX_N], imax;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        imax = max(imax, a[i]);
    }
    int p = a[0];
    for(int i = 1; i < n; i++)
        p = gcd(p, a[i]);
    int ans = imax/p - n;
    printf(ans&1 ? "Alice\n" : "Bob\n");
    return 0;
}
