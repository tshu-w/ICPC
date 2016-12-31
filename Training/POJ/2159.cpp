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
	string s1, s2;
	int a[105], ch1[30], ch2[30];
	memset(a, 0, sizeof a);
	memset(ch1, 0, sizeof ch1);
	memset(ch2, 0, sizeof ch2);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i)
		++ch1[s1[i] - 'A'];
	for (int i = 0; i < s2.size(); ++i)
		++ch2[s2[i] - 'A'];
	sort(ch1, ch1 + 30);
	sort(ch2, ch2 + 30);
	bool flag = true;
	for (int i = 0; i < 30; ++i)
		if (ch1[i] != ch2[i]) {
			flag = false;
			break;
		}
	if (flag) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
	return 0;
}