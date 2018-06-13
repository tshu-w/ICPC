#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;
const int maxn = 2e5 + 10;

int n, K, A[maxn];
set<Pii> st;

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) scanf("%d", A + i);
    for (int i = 0; i < n; i++) st.insert(Pii(A[i] - K, A[i]));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(Pii(A[i], INT_MAX));
        if (it != st.begin()) it--;
        if (A[i] >= it->first && A[i] < it->second) continue;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}