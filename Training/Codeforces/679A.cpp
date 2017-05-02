#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int prime[MAX_N];
bool is_prime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (is_prime[i] && i < 50) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) 
                is_prime[j] = false;
        }
    return p;
}
int main(int argc, char const *argv[])
{
    int p = seive(100), cnt = 0;
    // for (int i = 0; i < p; ++i)
        // cout << prime[i] << " ";
    // cout << endl;
    // bool isPrime = false;
    for (int i = 0; i < p; ++i) {
        printf("%d\n", prime[i]);
        fflush(stdout);
        char res[5];
        scanf("%s", res);
        if (res[0] == 'y') {
            if (prime[i] < 10) {
                printf("%d\n", prime[i] * prime[i]);
                fflush(stdout);
                char res[5];
                scanf("%s", res);
                if (res[0] == 'y') {
                    cout << "composite" << endl;
                    return 0;
                }
            }
            ++cnt;
            if (cnt >= 2)
                break;
        }
    }
    if (cnt <= 1)
        cout << "prime" << endl;
    else 
        cout << "composite" << endl;
    return 0;
}