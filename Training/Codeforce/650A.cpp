#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 200010;
typedef struct point
{
	int x, y;
}P;
bool cmpx(P a, P b) {
	if (a.x < b.x)
		return 1;
	if (a.x == b.x && a.y < b.y)
		return 1;
	return 0;
}
bool cmpy(P a, P b) {
	if (a.y < b.y)
		return 1;
	if (a.y == b.y && a.x < b.x)
		return 1;
	return 0;
}
P pnt[maxn];
int main(int argc, char const *argv[])
{
	int n, curx, cury;
	unsigned long long ans= 0LL, cunt;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> pnt[i].x >> pnt[i].y;
	}
	sort(pnt, pnt + n, cmpx);
	curx = pnt[0].x;
	cury = pnt[0].y;
	cunt = 1;
	for (int i = 1; i < n; ++i) {
		if (pnt[i].x == curx)
			cunt++;
		else {
			ans += cunt * (cunt - 1) / 2;
			curx = pnt[i].x;
			cury = pnt[i].y;
			cunt = 1;
		}
	}
	ans += cunt * (cunt - 1) / 2;
	//cout << ans << endl;
	sort(pnt, pnt + n, cmpy);
	curx = pnt[0].x;
	cury = pnt[0].y;
	cunt = 1;
	for (int i = 1; i < n; ++i) {
		if (pnt[i].y == cury) {
			cunt++;
		}
		else {
			ans += cunt * (cunt - 1) / 2;
			curx = pnt[i].x;
			cury = pnt[i].y;
			cunt = 1;
		}
		//cout << ans << endl;
	}
	ans += cunt * (cunt - 1) / 2;
	curx = pnt[0].x;
	cury = pnt[0].y;
	cunt = 1;
	for (int i = 1; i < n; ++i) {
		if (pnt[i].y == cury && pnt[i].x == curx) {
			cunt++;
		}
		else {
			ans -= cunt * (cunt - 1) / 2;
			curx = pnt[i].x;
			cury = pnt[i].y;
			cunt = 1;
		}
		//cout << ans << endl;
	}
	ans -= cunt * (cunt - 1) / 2;
	cout << ans << endl;
	return 0;
}