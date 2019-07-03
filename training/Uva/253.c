#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int mark[6];
    char str[15];
    
    while ( gets(str) ) {
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < 3; i++)
            switch ( str[i] + str[6 - i - 1] ) {
                case 'b' + 'b' : mark[0]++;break;
                case 'b' + 'r' : mark[1]++;break;
                case 'b' + 'g' : mark[2]++;break;
                case 'r' + 'r' : mark[3]++;break;
                case 'r' + 'g' : mark[4]++;break;
                case 'g' + 'g' : mark[5]++;break;
            }
        int flag = 1;
        for (int i = 6; i < 9; i++)
            switch ( str[i] + str[17 - i]) {
                case 'b' + 'b' : mark[0]--;break;
                case 'b' + 'r' : mark[1]--;break;
                case 'b' + 'g' : mark[2]--;break;
                case 'r' + 'r' : mark[3]--;break;
                case 'r' + 'g' : mark[4]--;break;
                case 'g' + 'g' : mark[5]--;break;
            }
        for (int i = 0; i < 6; i++)
            if ( mark[i] ) flag = 0;
        printf( (flag)? "TRUE\n" : "FALSE\n");
    }

    return 0;
}