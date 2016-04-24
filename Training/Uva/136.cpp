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
const LL coeff[] = {2, 3, 5};

int main(int argc, char const *argv[])
{
	priority_queue<LL, vector<LL>, greater<LL> > que;
	set<LL> s;
	int x;
	que.push(1);
	s.insert(1);
	for (int i = 0; i < 1500; ++i) {
		x = que.top(); que.pop();
		for (int j = 0; j < 3; ++j) {
			LL x2 = x * coeff[j];
			if (!s.count(x2)) {
				que.push(x2);
				s.insert(x2);
				// cout << x << " " << x2 <<endl;
			}
		}
	}
	cout << "The 1500'th ugly number is " << x << ".\n";
	return 0;
}