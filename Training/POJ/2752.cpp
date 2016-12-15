#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
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
const int MAX_N = 400000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int nxt[MAX_N];
void getNext(const string &str) {
    int len = str.length();
    int j = 0, k;
    k = nxt[0] = -1;
    while (j < len) {
        if (k == -1 || str[j] == str[k]) 
            nxt[++j] = ++k;
        else k = nxt[k];
    }
}
string s;

int main(int argc, char const *argv[])
{
	IOS;
	while (cin >> s) {
		getNext(s);
		vector<int> v;
		int p = s.length();
		do {
			v.push_back(p);
			p = nxt[p];
		} while (p);
		for (int i = v.size() - 1; i >= 0; --i)
			printf("%d%c", v[i], i ? ' ' : '\n');
	}	
	return 0;
}