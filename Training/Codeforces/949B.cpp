// written at 15:59 on 09 Mar 2018
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
int q;

ll solve(ll x, ll l, ll r) {
    if (x % 2 == 1) return x / 2 + 1;
    else return solve(r + (x / 2 - (l - 1) / 2), r + 1, r + (r / 2 - (l - 1) / 2));
}

int main() {
    scanf("%lld%d", &n, &q);
    while (q--) {
        scanf("%lld", &x);
        printf("%lld\n", solve(x, 1, n));
    }
    return 0;
}
