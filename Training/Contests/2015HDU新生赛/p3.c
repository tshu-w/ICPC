#include "stdio.h"

int type(const int * A) {
    if (A[0] == A[1] && A[1] == A[2]) return 3;
    if (A[0] == A[1] || A[0] == A[2] || A[1] == A[2]) return 2;
    return 1;
}
int is_win(const int * Nias,const int * Ains) {
    int N[3], A[3];
    int typeN = type(Nias);
    int typeA = type(Ains);
    if (typeN > typeA) return 1;
    if (typeN < typeA) return 0;
    if (typeN == 1) {
        for (int i = 0 ; i < 3; i++) {
            N[i] = Nias[i];
            A[i] = Ains[i];
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (N[i] < N[j]) {
                    int temp = N[i];
                    N[i] = N[j];
                    N[j] = temp;
                }
                if (A[i] < A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        for (int i = 0; i < 3; i++)
            if (Nias[i] > Ains[i]) return 1;
            else
                if (Nias[i] < Ains[i]) return 0;
    }
    if (typeN == 2) {
        int sgl1 = Nias[0]^Nias[1]^Nias[2];
        int sgl2 = Ains[0]^Ains[1]^Ains[2];
        int dbl1, dbl2;
        for (int i = 0; i < 3; i++) {
            if (Nias[i] != sgl1) dbl1 = Nias[i];
            if (Ains[i] != sgl2) dbl2 = Ains[i];
        }
        if (dbl1 > dbl2) return 1;
        if (dbl1 < dbl2) return 0;
        if (sgl1 > sgl2) return 1;
        else return 0;
    }
    if (typeN == 3) {
        if (Nias[0] > Ains[0]) return 1;
        else return 0;
    }
}
int main(int argc, char const *argv[])
{
    int t, Nias[3], Ains[3];
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; i++)
            scanf("%d", &Nias[i]);
        for (int i = 0; i < 3; i++)
            scanf("%d", &Ains[i]);
        if (is_win(Nias, Ains)) printf("1.000\n");
        else {
            double pos = 0.0;
            for (int i = 0; i < 3; i++) {
                int cases = 0;
                for (int j = 1; j <= 6; j++)
                    if (j != Nias[i]) {
                        int temp = Nias[i];
                        Nias[i] = j;
                        if (is_win(Nias, Ains)) cases++;
                        Nias[i] = temp;
                    }
                if ((double)cases / 6.0 > pos) pos = (double)cases / 6.0;
                //printf("%.3lf\n", pos);
            }
            printf("%.3lf\n", pos);
        }
    }
    return 0;
}