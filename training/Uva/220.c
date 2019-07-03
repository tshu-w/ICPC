#include <stdio.h>

const int movepace[8][2] = {
    { 0, 1}, { 0, -1}, {  1, 0}, { -1,  0},
    { 1, 1}, { 1, -1}, { -1, 1}, { -1, -1},
};

char checkerboarder[10][10];
int nBlack, nWhite;
char crtPlayer;

int IsLegalMove( const int x, const int y) {
    int flag = 0;
    char oposite = ( crtPlayer == 'B')? 'W' : 'B';
    for (int i = 0; i < 8 && !flag; i++) {
        int cases = 0;
        int r = x + movepace[i][0], c = y + movepace[i][1];
        while ( r >= 0 && r < 8 && c>= 0 && c < 8 )
            if ( checkerboarder[r][c] == oposite ) {
                r += movepace[i][0];
                c += movepace[i][1];
                cases = 1;
            }
            else {
                if ( checkerboarder[r][c] == crtPlayer && cases) {
                    flag = 1;
                    break;
                }
                break;
            }
    }
    return flag;
}

void List() {
    int cases = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (checkerboarder[i][j] == '-')
                if ( IsLegalMove(i, j)) {
                    if ( cases++ ) putchar(' ');
                    printf("(%d,%d)", i + 1, j + 1);
                }
    if (cases) puts("");
    else printf("No legal move.\n");
}

void Change( const int x, const int y ) {
    char oposite = ( crtPlayer == 'B')? 'W' : 'B';
    for (int i = 0; i < 8; i++) {
        int flag = 0, cases = 0;
        int r = x + movepace[i][0], c = y + movepace[i][1];
        while ( r >= 0 && r < 8 && c>= 0 && c < 8 ) {
            if ( checkerboarder[r][c] == oposite ) {
                r += movepace[i][0];
                c += movepace[i][1];
                cases = 1;
            }
            else {
                if ( checkerboarder[r][c] == crtPlayer && cases) {
                    flag = 1;
                    break;
                }
                break;
            }
        }
        if (flag) {
            int r = x + movepace[i][0], c = y + movepace[i][1];
            while ( r >= 0 && r < 8 && c>= 0 && c < 8 ) {
                if ( checkerboarder[r][c] == oposite ) {
                    checkerboarder[r][c] = crtPlayer;
                    if ( crtPlayer == 'B') {
                        nWhite--;
                        nBlack++;
                    }
                    else {
                        nBlack--;
                        nWhite++;
                    }
                    r += movepace[i][0];
                    c += movepace[i][1];
                }
                else
                    break;
            }

        }
    }
}

void Move(char * cmd) {
    int x, y;
    x = cmd[1] - '1';
    y = cmd[2] - '1';
    if ( !IsLegalMove(x, y) )
        crtPlayer = ( crtPlayer == 'B' )? 'W' : 'B';
    checkerboarder[x][y] = crtPlayer;
    if (crtPlayer == 'B') nBlack++;
    else nWhite++;
    Change(x, y);
    crtPlayer = ( crtPlayer == 'B' )? 'W' : 'B';
    printf("Black - %2d White - %2d\n", nBlack, nWhite);
}

void Quit() {
    for ( int i = 0; i < 8; i++ ) {
        for ( int j = 0; j < 8; j++)
            putchar(checkerboarder[i][j]);
        puts("");
    }
}

void eatline() {
    while (getchar() != '\n')
        ;
}

int main(int argc, const char * argv[]) {
    char cmd[5];
    int t;
    scanf("%d", &t);
    eatline();
    while ( t-- )
    {
        nBlack = 0;
        nWhite = 0;
        for ( int i = 0; i < 8; i++ ) {
            gets(checkerboarder[i]);
            for ( int j = 0; j < 8; j++ ) {
                if ( checkerboarder[i][j] == 'B') nBlack++;
                if ( checkerboarder[i][j] == 'W') nWhite++;
            }
        }
        scanf("%c", &crtPlayer);
        eatline();
        do {
            gets(cmd);
            if ( cmd[0] == 'L' )
                List();
            else
            if ( cmd[0] == 'M' ) {
                Move( cmd );
            }
            else {
                Quit();
            }
        } while ( cmd[0] != 'Q');
        if ( t ) puts("");
    }
    
    return 0;
}