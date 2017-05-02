#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
    double n;
    while (~scanf("%lf", &n)) 
        printf("%.2lf\n", fabs(n));
    return 0;
}