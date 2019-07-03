#include <stdio.h>
#include <string.h>

const int dir[][3] = {
    { 1, 0, 0}, {0,  1, 0}, {0, 0,  1},
    {-1, 0, 0}, {0, -1, 0}, {0, 0, -1},
};
struct Pieces
{
    int x, y, z;
    int step;    
}S, list[50000], lt, cur;
char maze[35][35][35];
int l, r, c, ans, vis[35][35][35];
int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d", &l, &r, &c) && l && r && c) {
        memset(maze, 0, sizeof(maze));
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%s", maze[i][j]);
                for (int k = 0; k < c; k++)
                    if (maze[i][j][k] == 'S') {
                        S.x = i;
                        S.y = j;
                        S.z = k;
                        S.step = 0;
                    }
            }
            while (getchar() != '\n')
                ;
        }
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 1, flag = 1;
        list[head] = S;
        vis[S.x][S.y][S.z] = 1;
        while (head < tail) {
            //printf("%d : %d %d %d\n", head, list[head].x, list[head].y, list[head].z);
            cur = list[head];
            if (maze[cur.x][cur.y][cur.z] == 'E') {
                printf("Escaped in %d minute(s).\n", cur.step);
                flag = 0;
                break;
            }
            for (int i = 0; i < 8; i++) {
                lt.x = cur.x + dir[i][0];
                lt.y = cur.y + dir[i][1];
                lt.z = cur.z + dir[i][2];
                lt.step = cur.step + 1;
                if (lt.x >= 0 && lt.x < l && lt.y >= 0 && lt.y < r && lt.z >= 0 && lt.z < c)
                    if ((maze[lt.x][lt.y][lt.z] == '.' || maze[lt.x][lt.y][lt.z] == 'E')
                        && !vis[lt.x][lt.y][lt.z]) {
                        list[tail++] = lt;
                        vis[lt.x][lt.y][lt.z] = 1;
                    }
            }
            head++;
        }
        if (flag) 
            printf("Trapped!\n");
    }    
    return 0;
}