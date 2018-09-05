// written at 15:21 on 20 Jul 2018
#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

struct Query {
    int l, r, id;
    bool operator < (const Query &q) const {
        return r < q.r;
    }
};

int sum(vector<int> &bit, int i) {
    int res = 0;
    for (; ~i; i -= ~i & i + 1)
        res += bit[i];
    return res;
}

void add(vector<int> &bit, int i, int x) {
    for (; i < SZ(bit); i += ~i & i + 1)
        bit[i] += x;
}

int main() {
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        int tot = 0;
        vector<int> a(n), first(n, -1), last(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
            last[a[i]] = i;
            if (first[a[i]] == -1) first[a[i]] = i, tot++;
        }
        vector<Query> queries;
        for (int i = 0, l, r; i < q; i++) {
            scanf("%d%d", &l, &r);
            queries.push_back(Query{l - 1, r - 1, i});
        }
        sort(queries.begin(), queries.end());
        vector<int> ans(q), bit(n);
        for (int i = 0, k = 0; i < n; i++) {
            while (k < q && queries[k].r == i) {
                ans[queries[k].id] = tot - (sum(bit, i) - sum(bit, queries[k].l));
                k++;
            }
            if (last[a[i]] == i) add(bit, first[a[i]], 1);
        }
        for (auto x : ans) printf("%d\n", x);
    }
    return 0;
}
