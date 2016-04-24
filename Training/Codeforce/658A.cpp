#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

const int maxn = 55;

int main(int argc, char const *argv[])
{
	int n, c, t[maxn], p[maxn];
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	int x = 0, score1 = 0;
	for (int i = 0; i < n; ++i) {
		x += t[i];
		score1 += max(0, p[i] - c * x); 
	}
	int score2;
	x = 0;
	for (int i = n - 1; i >= 0; --i) {
		x += t[i];
		score2 += max(0, p[i] - c * x);
	}
	if (score1 > score2)
		cout << "Limak" << endl;
	else if (score1 == score2)
		cout << "Tie" << endl;
	else 
		cout << "Radewoosh" << endl;
	return 0;
}