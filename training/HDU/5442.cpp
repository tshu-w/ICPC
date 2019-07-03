#include <bits/stdc++.h>

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

int getMaxString(const string &str) {
    int len = (int)str.length();
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = str[(i + k) % len] - str[(j + k) % len];
        if (t == 0) ++k;
        else { 
            if (t > 0) j += k + 1;
            else i += k + 1;
            if (i == j) ++j;
            k = 0;
        }
    }
    return min(i, j);
}
int nxt[MAX_N];
void getNext(const string &str) {
    int j = 0, k, len = str.length();
    nxt[0] = k = -1;
    while (j < len) {
        if (k == -1 || str[j] == str[k])
            nxt[++j] = ++k;
        else k = nxt[k];
    }
}
int kmp(const string &tar, const string &pat) {
    getNext(pat);
    int j, k, res;
    int lenT = tar.length(), lenP = pat.length();
    res = j = k = 0;
    while (j < lenT) {
        if (k == -1 || tar[j] == pat[k])
            ++j, ++k;
        else k = nxt[k];
        if (k == lenP) {
            res = max(res, j - lenP + 1);
            k = nxt[k];
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int t, n, a, b;
    string s, s0, s1;
    cin >> t;
    while (t--) {
        s0.clear();s1.clear();
        cin >> n;
        cin >> s;
        a = getMaxString(s);
        for (int i = 0; i < n; ++i) 
            s0 += (s[(a + i) % n]);
        reverse(s.begin(), s.end());
        b = getMaxString(s);
        for (int i = 0; i < n; ++i) 
            s1 += (s[(b + i) % n]);

        for (int i = 0; i < n - 1; ++i)
            s += s[i];
        // b = n - s.rfind(s1) - 1;
        b = n - kmp(s, s1);
        if (s0.compare(s1) == 0) {
            if (a <= b)
                cout << a + 1 << " 0" << endl;
            else
                cout << b + 1 << " 1" << endl;
        } else {
            if (s0.compare(s1) > 0)
                cout << a + 1 << " 0" << endl;
            else 
                cout << b + 1 << " 1" << endl;
        }
    }    
    return 0;
}