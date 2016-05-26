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
const int MAX_N = 1e5 + 5;

int main(int argc, char const *argv[])
{
	int n, a;
	set<int> tree;
	map<int, int> deep;
	scanf("%d", &n);
	scanf("%d", &a);
	tree.insert(a);
	deep[a] = 0;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &a);
		set<int>::iterator lp, rp;
	 	lp = tree.lower_bound(a);
		rp = tree.upper_bound(a);
		// cout << *lp << " " << *rp << endl;
		if (lp == tree.begin()) {
			cout << *rp << " ";
			deep[a] = deep[*rp] + 1;
		} else {
			lp--;
			if (rp == tree.end()) {
				cout << *lp << " ";
				deep[a] = deep[*lp] + 1;
			} else {
				set<int>::iterator fa;
				fa = (deep[*lp] > deep[*rp])? lp : rp;
				cout << *fa << " ";
				deep[a] = deep[*fa] + 1;			
			}
		}
		tree.insert(a);
	}
	cout << endl;
    return 0;
}