#include<cstdio>
#include<cstring>
using namespace std;
const int N = 12;

char brd[N][N];
int dx[] = { -1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int hx[] = { -2, -1, -2, -1, 1, 2, 1, 2};  //马将军
int hy[] = { -1, -2, 1, 2, -2, -1, 2, 1};
int tx[] = { -1, -1, -1, -1, 1, 1, 1, 1};  //马蹩脚
int ty[] = { -1, -1, 1, 1, -1, -1, 1, 1};
int cr[2], cc[2];  //记录炮的坐标

int check(int r, int c)
{
    int i, j, k, tr, tc, cnt;
    if(r < 1 || r > 3 || c < 4 || c > 6) return 1;
    
    for (j = c - 1; j > 0; --j)   //行被车
    {
        if(brd[r][j])
            if(brd[r][j] == 'R') return 1;
            else break;
    }
    for (j = c + 1; j <= 9; ++j)
    {
        if(brd[r][j])
            if(brd[r][j] == 'R') return 1;
            else break;
    }
    
    for (i = r - 1; i > 0; --i)  //列被车
    {
        if(brd[i][c])
            if(brd[i][c] == 'R') return 1;
            else break;
    }
    for (i = r + 1; i <= 10; ++i) //列被车或将
    {
        if(brd[i][c])
            if(brd[i][c] == 'R' || brd[i][c] == 'G') return 1;
            else break;
    }
    
    for(int k = 0; k < 2; ++k)    //被炮将军
    {
        if(cr[k] == r)   //行有炮
        {
            for(j = c - 1, cnt = 0; j > cc[k]; --j) if(brd[r][j]) ++cnt;
            if(cnt == 1) return 1;
            for(j = c + 1, cnt = 0; j < cc[k]; ++j) if(brd[r][j]) ++cnt;
            if(cnt == 1) return 1;
        }
        if(cc[k] == c)   //列有炮
        {
            for(i = r - 1, cnt = 0; i > cr[k]; --i) if(brd[i][c]) ++cnt;
            if(cnt == 1) return 1;
            for(i = r + 1, cnt = 0; i < cr[k]; ++i) if(brd[i][c]) ++cnt;
            if(cnt == 1) return 1;
        }
    }
    
    for(int k = 0; k < 8; ++k)   //被马将军
    {
        tr = r + hx[k], tc = c + hy[k];
        if(tr < 1 || tr > 10 || tc < 1 || tc > 9) continue;
        if(brd[tr][tc] == 'H' && (!brd[r + tx[k]][c + ty[k]]))
            return 1;
    }
    
    return 0;
}

int main()
{
    char s[5];
    int n, r, c, x, y;
    while(scanf("%d%d%d", &n, &r, &c), n || r || c)
    {
        memset(brd, 0, sizeof(brd));
        cr[0] = cc[0] = cr[1] = cc[1] = 0;
        
        while(n--)
        {
            scanf("%s%d%d", s, &x, &y);
            if(s[0] == 'C')
            {
                if(cr[0]) cr[1] = x, cc[1] = y;
                else cr[0] = x, cc[0] = y;
            }
            brd[x][y] = s[0];
        }
        
        int cnt = 0;
        for(int i = 0; i < 4; ++i)
            cnt += check(r + dx[i], c + dy[i]);
        if(cnt < 4) puts("NO");
        else puts("YES");
    }
    return 0;
}