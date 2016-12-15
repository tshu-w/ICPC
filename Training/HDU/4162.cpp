#include <bits/stdc++.h>

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
const int MAX_N = 300000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

char s[MAX_N];
int len;

int getMinString(char s[], int len) {  
    int i = 0, j = 1, k = 0;  
    while(i < len && j < len && k < len) {
        int t = s[(i+k)%len] - s[(j+k)%len];
        if(t == 0) k++;
        else {
            if(t > 0) i += k + 1;//getMaxString: t < 0
            else j += k + 1;
            if(i==j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%s", s)) {
		len = strlen(s);
		s[len] = s[0];
		for (int i = 0; i < len; ++i)
			s[i] = (s[i + 1] - s[i] + 8) % 8 + '0';
		s[len] = 0;
		int pos = getMinString(s, len);
		printf("%s", s + pos);
		s[pos] = 0;
		puts(s);
	}
	return 0;
}