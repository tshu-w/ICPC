#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int maxn = 205, maxm = 1005;
int n, m, w, graph[maxn][maxn], way[maxm], edge[maxn][10];
int dfs(int u, int k) {
	cout << u << "    " << k << " " << graph[14][6] << endl;
    if (k > m) {
    	cout << m << endl;
    	for (int i = 0; i <= m; ++i) {
    	    cout << way[i];
    	    if (i != m)
    	        cout << ' ';
    	    else 
    	        cout << endl;
    	}
        return 1;
    }
    for (int i = 1; i <= edge[u][0]; ++i) {
        int v = edge[u][i];
        if (graph[u][v]) {
            graph[u][v]--;
            graph[v][u]--;
            way[k] = v;
            if (dfs(v, k + 1))
            	return 1;
        	graph[u][v]++;
            graph[v][u]++;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    memset(graph, 0, sizeof(graph));
    memset(edge, 0, sizeof(edge));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x][0]++;
        edge[x][edge[x][0]] = y;
        edge[y][0]++;
        edge[y][edge[y][0]] = x;
        ++graph[x][y];
    	++graph[y][x];
    }
    for (int i = 1; i <= n; ++i) {
        sort(edge[i] + 1, edge[i] + edge[i][0] + 1);
        cout << "i = " << i << "   ";
        for (int j = 1; j <= edge[i][0]; ++j) 
            cout << edge[i][j] << " ";
        cout << endl;
    }
    //cout << "sucess" << endl;
    way[0] = 1;
    dfs(1, 1);
    //cout << "sucess" << endl;
    return 0;
}