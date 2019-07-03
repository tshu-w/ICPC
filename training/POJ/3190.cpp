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
const int MAX_N = 50000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, ans[MAX_N];
pair<Pii,int> A[MAX_N];
priority_queue<Pii, vector<Pii>, greater<Pii> > que;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &A[i].first.first, &A[i].first.second);
        A[i].second = i + 1;
    }
    sort(A, A + N);
    que.push(Pii(A[0].first.second, 1)); ans[A[0].second] = 1;
    for (int i = 1; i < N; ++i) {
        int id = A[i].second;
        if (que.top().first < A[i].first.first) {
            ans[id] = que.top().second;
            que.pop();
            que.push(Pii(A[i].first.second, ans[id]));
        } else {
            ans[id] = que.size() + 1;
            que.push(Pii(A[i].first.second, que.size() + 1));
        }
    }
    printf("%lu\n", que.size());
    for (int i = 1; i <= N; ++i)
        printf("%d\n", ans[i]);
    return 0;
}