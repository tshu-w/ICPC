#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
// const int MAX_N = ;

const double PI = acos(-1.);

int main(int argc, char const *argv[])
{
    ull n;
    scanf("%llu", &n);
    if (n % 3 == 0)
        printf("%llu\n",  2 * n / 3);
    else
        printf("%llu\n", (n / 3) * 2 + 1);
    return 0;
}
