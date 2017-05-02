#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

const int maxn = 100005;

int n, d, h, cnt = 1;

int main(int argc, char const *argv[])
{
    cin >> n >> d >> h;
    if (h * 2 < d || (d == 1 && d * 2 < n)) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= h; ++i, cnt++)
            cout << cnt << " " << cnt + 1 << endl;
        int last = cnt - 1;
        for (int i = 1; i < n - d; ++i, cnt++)
            cout << last << " " << cnt + 1 << endl;
        if (d - h > 0) {
            cout << 1 << " " << ++cnt << endl;
            for (int i = 1; i < d - h; ++i, cnt++)
                cout << cnt << " " << cnt + 1 << endl;
        }
    }
    return 0;
}