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
typedef pair<int, int> Pii;

const int INF = INT_MAX;
const int MAX_N = 10000 + 10;
const int MAX_M = 10 + 5;

map<string, int> IDcache;
vector<string> Scache;
vector<int> tbl[MAX_N];

int getID(string s) {
	if (IDcache.count(s)) 
		return IDcache[s];
	Scache.push_back(s);
	return IDcache[s] = Scache.size() - 1;
}
int main(int argc, char const *argv[])
{
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		string line, word;
		// cout << n << " " << m << endl;
		Scache.clear();
		IDcache.clear();
		getline(cin, line);
		for (int i = 0; i < n; ++i) {
			tbl[i].clear();
			getline(cin, line);
			// cout << line << endl;
			word.clear();
			for (int j = 0; j < line.length(); ++j) 
				if (line[j] == ',') {
					tbl[i].push_back(getID(word));
					// cout << word << endl;
					word.clear();
				} else word += line[j];
			tbl[i].push_back(getID(word));
			// cout << word << endl;
		}
		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < n; ++j)
		// 		printf("%d ", tbl[i][j]);
		// 	printf("\n");
		// }
		bool flg = true;
		for (int i = 0; i < m && flg; ++i)
			for (int j = i + 1; j < m && flg; ++j) {
				map<Pii, int> pnt;
				for (int k = 0; k < n; ++k) {
					Pii tmp = make_pair(tbl[k][i], tbl[k][j]);
					if (pnt.count(tmp)) {
						printf("NO\n");
						printf("%d %d\n", pnt[tmp] + 1, k + 1);
						printf("%d %d\n", i + 1, j + 1);
						flg = false;
						break;
					} else 
						pnt[tmp] = k;
				}
			}
		if (flg) 
			printf("YES\n");
	}
	return 0;
}