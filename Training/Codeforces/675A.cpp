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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const int INF = INT_MAX;
const int MAX_N = 50005;

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c == 0) {
        if (a == b)
            printf("YES\n");
        else 
            printf("NO\n");
    } else {
        if ((b - a) % c == 0 && (b - a) / c >= 0)
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}