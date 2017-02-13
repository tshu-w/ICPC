#include "stdio.h"

int main(int argc, char const *argv[])
{
    char ch[5];
    while (~scanf("%s", ch)) {
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (ch[i] > ch[j]) {
                    char temp = ch[i];
                    ch[i] = ch[j];
                    ch[j] = temp;
                }
        printf("%c %c %c\n", ch[0], ch[1], ch[2]);
    }
    return 0;
}