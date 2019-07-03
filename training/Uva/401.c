#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]= {"not a palindrome", "a mirrored string", "a regular palindrome", "a mirrored palindrome"};

char r(char ch){
    if (isalpha(ch)) return rev[ch-'A'];
        else return rev[ch-'0'+25];
}

int main(int argc, const char * argv[]) {
    char s[30];
    
    while (scanf("%s",s)==1) {
        int m = 1,n = 1;
        unsigned long len=strlen(s);
        for (int i = 0; i < (len+1)/2; i++){
            if (s[i] != s[len-i-1]) m = 0;
            if (r(s[i]) != s[len-i-1]) n = 0;
        };
        printf("%s -- is %s.\n\n",s,msg[m*2+n]);
    }

    return 0;
}