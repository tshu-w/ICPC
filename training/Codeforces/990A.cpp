#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

ll n, m, a, b;

int main() {
    cin >> n >> m >> a >> b;
    cout << min(n % m * b, (m - n % m) * a) << endl;
    return 0;
}