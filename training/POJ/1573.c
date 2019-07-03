#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int r, c, p, graph[20][20];
    char grid[20][20];
    while (scanf("%d%d%d", &r, &c, &p) && r) {
        memset(grid, 0, sizeof(grid));
        memset(graph, -1, sizeof(graph));
        for (int i = 0; i < r; i++)
            scanf("%s", grid[i]);
        int x = 0, y = p - 1, cnt = 0;
        while (1) {
            graph[x][y] = cnt++;
            switch (grid[x][y]) {
                case 'N' : x--; break; 
                case 'S' : x++; break;
                case 'E' : y++; break;
                case 'W' : y--; break;
            }
            /*
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++)
                    printf("%3d", graph[i][j]);
                printf("\n");
            }
            printf("\n%d %d\n", x, y);
            //*/
            if (x < 0 || x == r || y < 0 || y == c) {
                printf("%d step(s) to exit\n", cnt);
                break;
            }
            if (graph[x][y] != -1) {
                printf("%d step(s) before a loop of %d step(s)\n", graph[x][y], cnt - graph[x][y]);
                break;
            }
        }
    }
    return 0;
}