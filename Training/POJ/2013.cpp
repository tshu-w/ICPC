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
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
    int n, tt = 0;
    string name[MAX_N];
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i)
            cin >> name[i];
        cout << "SET " << ++tt << endl;
        for (int i = 0; i < n; ++i, ++i) 
            cout << name[i] << endl;
        for (int i = (n & 1)? n - 2 : n - 1; i > 0; --i, --i) 
            cout << name[i] << endl;
    }
    return 0;
}