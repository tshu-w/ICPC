#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
    int n;
    string s;
    for (int i = 1; i < 500; ++i) {
        s += to_string(i);
        if (s.length() > 1000) {
            // printf("%d\n", i);
            break;
        }
    }
    scanf("%d", &n);
    printf("%c\n", s[n - 1]);
    return 0;
}