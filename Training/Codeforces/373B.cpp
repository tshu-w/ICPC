#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	long long w, m, k, pw;
	cin >> w >> m >> k;
	w /= k;
	pw = 1;
	for (int i = 1; i < 20; ++i, pw *= 10) if (pw * 10 > m){
		long long tmp;
		if (pw > m)
			tmp = pw * 9;
		else
			tmp = pw * 10 - m;
		tmp *= i;
		//cout << tmp << ' ' << w << ' ' << pow(10, i - 1) << endl;
		if (w > tmp)
			w -= tmp;
		else {
			long long ans;
			if (pw > m)
				ans = w / i + pw - m;
			else
				ans = w / i;
			cout << ans << endl;
			break;
		}
	}
	return 0;
}
