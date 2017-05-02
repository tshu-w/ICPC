// #include <bits/stdc++.h>
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
#include <bitset>

using namespace std;

typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef long double LD;

const int INF = INT_MAX;
const int MAX_N = 10000 + 10;

bool flag[MAX_N][5];
int main(int argc, char const *argv[])
{
    int len;
    string s;
    set<string> ans;
    cin >> s;
    len = (int)s.length();
    flag[len][2] = flag[len][3] = true;
    for (int i = len - 1; i > 4; --i) 
        for (int j = 2; j <= 3; ++j) {
            if (i + j > len) continue;
            // cout << s.substr(i, j) << endl;
            string nxt;
            if (i + j == len)
                nxt = "";
            else nxt = s.substr(i + j, j);
            if (flag[i + j][5 - j] || (flag[i + j][j] && nxt != s.substr(i, j)))
                flag[i][j] = true;
        }
    for (int i = 5; i < len; ++i)
        for (int j = 2; j <= 3; ++j)
            if (i + j <= len &&  flag[i][j])
                ans.insert(s.substr(i, j));

    cout << ans.size() << endl;
    set<string>::iterator it;
    for (it = ans.begin(); it != ans.end(); ++it)
        cout << *it << endl;
    return 0;
}