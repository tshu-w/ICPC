// written at 20:03 on 31 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e3 + 10;

int n, A[MAX_N];

int main() {
    while(scanf("%d", &n) && n) {
        while (scanf("%d", A) && A[0]) {
            stack<int> st;
            bool ok = true;
            for (int i = 1; i < n; i++) scanf("%d", A + i);
            int i = 0, j = 1;
            while (i < n) {
                if (j == A[i]) i++, j++;
                else if (st.size() && A[i] == st.top()) st.pop(), i++;
                else if (j < A[i]) st.push(j++);
                else { ok = false; break;}
            }
            // dprint(A, A + n);
            puts(ok? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}
