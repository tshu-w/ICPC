#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    char * options[12] = {
        "x^y^z", "x^z^y",
        "(x^y)^z", "(x^z)^y",
        "y^x^z", "y^z^x",
        "(y^x)^z", "(y^z)^x",
        "z^x^y", "z^y^x",
        "(z^x)^y", "(z^y)^x",
    };
    double a[12], max, x, y, z;
    int nmax;
    scanf("%lf%lf%lf", &x, &y, &z);
    if (x > 1 &&  y > 1 && z > 1) {
        a[0]  = log(log(x)) + z * log(y);
        a[1]  = log(log(x)) + y * log(z);
        a[2]  = log(log(x)) + log(y) + log(z);
        a[3]  = a[2];
        a[4]  = log(log(y)) + z * log(x);
        a[5]  = log(log(y)) + x * log(z);
        a[6]  = log(log(y)) + log(z) + log(x);
        a[7]  = a[6];
        a[8]  = log(log(z)) + y * log(x);
        a[9]  = log(log(z)) + x * log(y);
        a[10] = log(log(z)) + log(x) + log(y);
        a[11] = a[10];
    }
    else {
        if (x != 1) {
            a[0]  = log(x) * pow(y, z);
            a[1]  = log(x) * pow(z, y);
            a[2]  = log(x) * y * z;
            a[3]  = a[2];
        } 
        else a[0] = a[1] = a[2] = a[3] = 0;
        if (y != 1) {
            a[4]  = log(y) * pow(x, z);
            a[5]  = log(y) * pow(z, x);
            a[6]  = log(y) * z * x;
            a[7]  = a[6];
        } 
        else a[4] = a[5] = a[6] = a[7] = 0;
        if (z != 1) {
            a[8]  = log(z) * pow(x, y);
            a[9]  = log(z) * pow(y, x);
            a[10] = log(z) * x * y;
            a[11] = a[10];
        }
        else a[8] = a[9] = a[10] = a[11] = 0;
    }
    max = a[0];nmax = 0;
    for (int i = 0; i < 12; i++) {
        //printf("%.15lf\n", a[i]);
        if ( a[i] > max ) {
            max = a[i];
            nmax = i;
        }
    }
    printf("%s\n", options[nmax]);
    return 0;
}