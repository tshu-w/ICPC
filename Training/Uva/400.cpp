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
const int MAX_N = 100 + 10;
const int max_col = 60;

void print(const string &s, int len, char extra) {
  cout << s;
  for(int i = 0; i < len-s.length(); i++)
    cout << extra;
}
int main(int argc, char const *argv[])
{
	int n;
	string que[MAX_N];
	while (~scanf("%d", &n)) {
		int m = 0;
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> que[i];
			m = max((int)que[i].length(), m);
		}
		int cols = (max_col - m) / (m + 2) + 1;
		int rows = (n - 1) / cols + 1;
		// cout << cols << " " << rows << endls;
		sort(que, que + n);
		print("", 60, '-');
		printf("\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				int index = j * rows + i;
				if (index < n) 
					print(que[index], (j + 1 == cols)? m : m + 2, ' ');
			}
			printf("\n");
		}
	}
	return 0;
}