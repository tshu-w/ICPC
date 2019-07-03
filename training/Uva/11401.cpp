// written at 13:59 on 11 Mar 2017 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n;
    while (cin >> n && n >= 3) {
        cout << ((n - 2) * (n - 1) * (2 * n - 3) / 6  - (n - 1) / 2) / 4 << endl;
    }
    return 0;
}