#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 3e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, q;
vector<int> graph[MAX_N];
int size[MAX_N], max_subtree[MAX_N], centroid[MAX_N], pre[MAX_N];

bool is_centroid(int v, int c) {
    return ((size[v] - size[c]) * 2 <= size[v] && size[max_subtree[c]] * 2 <= size[v]);
}
void dfs_size(int v, int p) {
    size[v] = 1;
    max_subtree[v] = 0;
    pre[v] = p;
    for (int i = 0; i < graph[v].size(); ++i) {
        dfs_size(graph[v][i], v);
        size[v] += size[graph[v][i]];
        if (size[max_subtree[v]] < size[graph[v][i]]) {
            max_subtree[v] = graph[v][i];
        }
    }
}
void dfs_centroid(int v) {
    // cout << v << endl;
    for (int i = 0; i < graph[v].size(); ++i) 
        dfs_centroid(graph[v][i]);
    if (size[v] == 1) {
        centroid[v] = v;
    } else {
        int c = centroid[max_subtree[v]];
        // cout << c << endl;
        while (!is_centroid(v, c)) {
            c = pre[c];
        }
        centroid[v] = c;
    }
}
int main(int argc, char const *argv[])
{
    IOS;
    cin >> n >> q;
    int v;
    for (int i = 1; i < n; ++i)
        cin >> v, graph[v].push_back(i + 1);
    dfs_size(1, 0);
    dfs_centroid(1);
    for (int i = 0; i < q; ++i)
        cin >> v, cout << centroid[v] << endl;
    return 0;
}