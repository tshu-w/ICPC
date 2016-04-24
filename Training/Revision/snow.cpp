#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int x1, y1, x2, y2, hour, min;
	double ans = 0.0;
	cin >> x1 >> y1;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		ans += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		//cout << ans << endl;
	}
	ans = ans * 2.0 / 1000.0 / 20.0;
	cout << ans << endl;
	hour = (int)(ans);
	min = (int)((ans - hour)*60.0 + 0.5);
	if (min == 60) {
		hour++;
		min = 0;
	}
	printf("%d:%02d\n", hour, min);
	return 0;
}