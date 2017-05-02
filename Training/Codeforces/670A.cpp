#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
    int n, imax, imin;
    cin >> n;
    imax = imin = n / 7 * 2;
    n  = n % 7;
    if (n <= 2) {
        imax += n;
    }
    else {
        imax += 2;
        if (n >= 6)
            imin += 7 - n;
    }
    cout << imin << " " << imax << endl;
    return 0;
}