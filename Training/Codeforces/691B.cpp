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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	map<char, char> m;
	m['A'] = 'A'; m['b'] = 'd'; m['d'] = 'b'; m['H'] = 'H'; m['I'] = 'I'; m['M'] = 'M'; m['O'] = 'O'; m['o'] = 'o';
	m['p'] = 'q'; m['q'] = 'p'; m['T'] = 'T'; m['U'] = 'U'; m['V'] = 'V'; m['v'] = 'v'; m['W'] = 'W'; m['w'] = 'w';
	m['X'] = 'X';m['x'] = 'x'; m['Y'] = 'Y'; 
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len / 2; ++i) {
		if (m[s[i]] != s[len - i - 1]) {
			cout << "NIE" << endl;
			return 0;
		}
	}
	cout << "TAK" << endl;
	return 0;
}