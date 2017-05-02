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
#include <iterator>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef set<int> Set;
const int INF = INT_MAX;
map<Set, int> IDcache;
vector<Set> Setcache;
const int MAX_N = 2005;

int getID(Set x) {
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}
int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;
            Set x;
            if (op[0] == 'P') s.push(getID(x));// set<int>() 空set？
            else if (op[0] == 'D') s.push(s.top());
            else {
                Set x1 = Setcache[s.top()];s.pop();
                Set x2 = Setcache[s.top()];s.pop();
                Set x;
                if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'A') { x = x2, x.insert(getID(x1));}
                s.push(getID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    
    return 0;
}