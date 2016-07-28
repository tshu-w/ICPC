/*
ID: volekin1
PROG: friday
LANG: C++11
*/
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
#define filename "friday"
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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int main(int argc, char const *argv[])
{
	freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
	int n, week[10], start = (13 - 1) % 7;
	cin >> n;
	fill(week, week + 10, 0);
	for (int i = 1900; i < 1900 + n; ++i) {
		if (is_leap(i))
			month[1] = 29;
		else 
			month[1] = 28;
		for (int j = 0; j < 12; ++j) {
			DEBUG("%d\n", start + 1);
			week[start]++;
			start = (start + month[j]) % 7;
		}
	}
	cout << week[5] << " " << week[6];
	for (int i = 0; i < 5; ++i)
		cout << " " << week[i];
	cout << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}