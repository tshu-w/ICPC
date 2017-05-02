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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

int main(int argc, char const *argv[])
{
    int t, kase = 0;
    while (scanf("%d", &t) && t) {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;
        for (int i = 0; i < t; ++i) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q, q2[MAX_N];
        while (true) {
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'S') break;
            if (cmd[0] == 'D') {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty()) 
                    q.pop();
            } else {
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}