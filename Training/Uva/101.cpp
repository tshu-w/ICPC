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

const int INF = INT_MAX;
const int MAX_N = 30;

int n;
vector<int> v[MAX_N];
vector<int>::iterator it;

void find_block(const int a, int &p, int &h) {
	for (p = 0; p < n; ++p) 
		for (h = 0; h < v[p].size(); ++h)
			if (v[p][h] == a) 
				return;
}
void clear_above(const int p, unsigned int h) {
	for (int i = h + 1; i < v[p].size(); ++i) {
		int top = v[p][i];
		v[top].push_back(top);
	}
	v[p].resize(h + 1);
}
void pile_onto(int p, int p2, int h) {
	for (int i = h; i < v[p].size(); ++i) 
		v[p2].push_back(v[p][i]);
	v[p].resize(h);
}
void print() {
	for (int i = 0; i < n; ++i) {
		printf("%d:", i);
		for (it = v[i].begin(); it != v[i].end(); ++it) 
			printf(" %d", *it);
		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int a, b;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; ++i)
		v[i].push_back(i);
	while (cin >> s1 >> a >> s2 >> b && s1 != "quit") {
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		// cout << pa << " " << ha << endl;
		// cout << pb << " " << hb << endl;
		if (pa == pb) continue;
		if (s2 == "onto") clear_above(pb, hb);
		if (s1 == "move") clear_above(pa, ha);
		pile_onto(pa, pb, ha);
		// print();
	}
	print();
	return 0;
}