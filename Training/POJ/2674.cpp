// C++ AC G++ TLE

#include <bits/stdc++.h>
#include <iomanip>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, it;
double L, V, p[MAX_N], dis;

struct Person {
	int dir;
	double pos;
	string name;
	Person() {}
	Person(string ch, double _pos, string _name):pos(_pos), name(_name) {
		if (ch[0] == 'p' || ch[0] == 'P')
			dir = 1;
		if (ch[0] == 'n' || ch[0] == 'N')
			dir = 0; 
	}
	bool operator < (const Person & p) const {
		return this->pos < p.pos;
	}
};

Person P[MAX_N];

int main(int argc, char const *argv[])
{
	while (cin >> N && N) {
		dis = 0;
		cin >> L >> V;
		for (int i = 0; i < N; ++i) {
			string ch, _name;
			double _pos;
			cin >> ch >> _pos >> _name;
			P[i] = Person(ch, _pos, _name);
			if (P[i].dir) dis = max(dis, L - P[i].pos);
			else dis = max(dis, P[i].pos);
		}
		for (int i = 0; i < N; ++i)
			if (P[i].dir) p[i] = P[i].pos + dis;
			else p[i] = P[i].pos - dis;
		sort(p, p + N);
		for (it = 0; it < N; ++it) {
			if (p[it] == 0.0 || p[it] == L) 
				break;
		}
		cout << setw(13) << fixed << setprecision(2) << (int)(dis / V * 100) / 100. << " " << P[it].name << endl;
	}
	return 0;
}