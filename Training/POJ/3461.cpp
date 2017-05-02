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
#include <bitset>

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
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t;
string s1, s2;

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
int kmp(const string &tar, const string &pat) {
    getNext(pat);
    int num, j, k;
    int lenT = tar.length(), lenP = pat.length();
    num = j = k = 0;
    while (j < lenT) {
        if(k == -1 || tar[j] == pat[k])
            j++, k++;
        else k = nxt[k];
        if(k == lenP) {
            // res = max(res, j - lenP);
            k = nxt[k];
            ++num;
        }
    }
    return num;//lenP - res - 1;
}

int main(int argc, char const *argv[])
{
    IOS;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        cout << kmp(s2, s1) << endl;
    }
    return 0;
}