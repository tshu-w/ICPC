#include <stdio.h>
#include <string.h>

const int dir[][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main(int argc, char const *argv[])
{
    int n, t, a, b, r, m;
    int robot[110][3], graph[110][110];
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        scanf("%d%d", &n, &m);
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= n; i++) {
            char ch;
            scanf("%d%d %c", &robot[i][0], &robot[i][1], &ch);
            //printf("printf%d %d %c\n", robot[i][0], robot[i][1], ch);
            switch (ch) {
                case 'N' : robot[i][2] = 0;break;
                case 'E' : robot[i][2] = 1;break;
                case 'S' : robot[i][2] = 2;break;
                case 'W' : robot[i][2] = 3;break;
            }
            graph[robot[i][0]][robot[i][1]] = i;

            /*
            for (int x = 1; x <= a; x++) {
                for (int y = 1; y <= b; y++)
                    printf("%d ", graph[x][y]);
                printf("\n");
            }
            printf("\n");
            //*/
        }
        int flag = 1;
        for (int i = 0; i < m; i++) {
            /*
            for (int x = 1; x <= a; x++) {
                for (int y = 1; y <= b; y++)
                    printf("%d ", graph[x][y]);
                printf("\n");
            }
            printf("\n");
            //*/
            int repeat, num, x, y;
            char ch;
            scanf("%d %c%d", &num, &ch, &repeat);
            //printf("printf %d %c %d\n", num, ch, repeat);
            if (ch == 'F') {
                x = robot[num][0];
                y = robot[num][1];
                for (int j = 0; j < repeat; j++) {
                    x += dir[robot[num][2]][0];
                    y += dir[robot[num][2]][1];
                    if (x == 0 || x == a + 1 || y == 0 || y == b + 1) {
                        if (flag)
                            printf("Robot %d crashes into the wall\n", num);
                        flag = 0;
                        break;
                    } 
                    if (graph[x][y]) {
                        if (flag)
                            printf("Robot %d crashes into robot %d\n", num, graph[x][y]);
                        flag = 0;
                        break;
                    }
                    graph[robot[num][0]][robot[num][1]] = 0;
                    robot[num][0] = x;
                    robot[num][1] = y;
                    graph[x][y] = num;
                }
            }
            else
                if (ch == 'L') {
                    robot[num][2] -= repeat;
                    while (robot[num][2] < 0) 
                        robot[num][2] += 4;
                }
                else {
                    robot[num][2] += repeat;
                    robot[num][2] %= 4;
                }
            // if (!flag) 
            //     break;
        }
        if (flag)
            printf("OK\n");
    }
    return 0;
}