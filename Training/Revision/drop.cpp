#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int work(int d, int i) {
	if (d == 1)
		return 1;
	int leaf = 0;
	if (i > 1 << (d - 2)) {
		leaf++;
		i -= 1 << (d - 2);
	}
	leaf += 2 * work(d - 1, i);
	return leaf;
}
int main(int argc, char const *argv[])
{
	int d, i;
	cin >> d >> i;
	cout << work(d, i) << endl;
	return 0;
}