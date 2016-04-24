#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

const int maxn = 105;

int main(int argc, char const *argv[])
{
    int n, ans;
    bool w[maxn][maxn], vanish[maxn];
    //init
    memset(w, 0, sizeof(w));
    memset(vanish, 0, sizeof(vanish));
    //readata
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int j;
        do {
            cin >> j;
            w[i][j] = true;
        } while (!j);
    }
    //floyed
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i) if (w[i][k])
            for (int j = 1; j <= n; ++j) if (w[k][j])
                w[i][j] = true;
    //shrink
    for (int i = 1; i <= n; ++i) if (!vanish[i])
        for (int j = 1; j <= n; ++j) if (!vanish[j] && w[i][j] && w[j][i]) {
            vanish[j] = true;
            //merge
            for (int k = 1; k <= n; ++k) {
                if (!vanish[k] && w[k][j]) {
                    w[k][i] = true;
                    w[k][j] = false;
                }
                if (!vanish[k] && w[j][k]) {
                    w[i][k] = true;
                    w[j][k] = false;
                }
                w[i][i] = false;
                w[i][j] = false;
            }
        }
    //count
    ans = 0;
    for (int i = 1; i <= n; ++i) if (!vanish[i]) {
        bool flag = true;
        for (int j = 1; j <= n; ++j) if (w[j][i]) {
            flag = false;
            break;
        }
        if (flag) 
            ++ans;
    }
    cout << ans << endl;
    return 0;
}