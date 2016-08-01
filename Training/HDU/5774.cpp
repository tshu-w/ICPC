//#include <bits/stdc++.h>
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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif  
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

string name[MAX_N] = {
    "Baltimore Bullets",
    "Boston Celtics",
    "Chicago Bulls",
    "Cleveland Cavaliers",
    "Dallas Mavericks",
    "Detroit Pistons",
    "Golden State Warriors",
    "Houston Rockets",
    "L.A. Lakers",
    "Miami Heat",
    "Milwaukee Bucks",
    "Minneapolis Lakers",
    "New York Knicks",
    "Philadelphia 76ers",
    "Philadelphia Warriors",
    "Portland Trail Blazers",
    "Rochester Royals",
    "San Antonio Spurs",
    "Seattle Sonics",
    "St. Louis Hawks",
    "Syracuse Nats",
    "Washington Bullets"
};
int num[MAX_N] = { 1, 17, 6, 1, 1, 3, 2, 2, 11, 3, 1, 5, 2, 2, 2, 1, 1, 5, 1, 1, 1, 1 };

int main(int argc, char const *argv[]) {
    int t;
    char str[MAX_N];
    scanf( "%d", &t ); fgets( str, MAX_N, stdin );
    for( int ncas = 1; ncas <= t; ++ncas ) {
        printf( "Case #%d: ", ncas );
        fgets( str, MAX_N, stdin );
        int len = strlen( str );
        str[len - 1] = 0;
        string s = str;
        bool flag = false;
        for( int i = 0; i < 23; ++i ) {
            if( name[i] == s ) {
                flag = true;
                printf( "%d\n", num[i] );
            }
        }
        if( !flag ) puts( "0" );
    }
    return 0;
}
