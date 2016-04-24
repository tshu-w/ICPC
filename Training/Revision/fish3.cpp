#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 110;

typedef struct data
{
    int fish, lake;
}Data;
class Heap
{
public:
    Heap():len(0) {};
    ~Heap() {};
    int getlen() {
        return len;
    }
    void sift(int i);
    int len;
    Data a[maxn];
};

void Heap::sift(int i) {
    Data tmp = a[i];
    while (i * 2 <= len) {
        if (i * 2 + 1 > len || a[i * 2].fish > a[i * 2 + 1].fish)
            i = i * 2;
        else
            i = i * 2 + 1;
        if (tmp.fish < a[i].fish)
            a[i / 2] = a[i];
        else {
        	i /= 2;
            break;
        }
    }
    a[i] = tmp;
}

int main(int argc, char const *argv[])
{
    int n, f[maxn], d[maxn], t[maxn], tm, T, ans, max(0);
    Heap hp;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    t[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> t[i];
        t[i] += t[i - 1];
    }
    cin >> T;
    for (int k = 1; k <= n; ++k) {
        tm = T - t[k];
        ans = 0;
        for (int i = 1; i <= k; ++i) {
            hp.a[i].fish = f[i];
            hp.a[i].lake = i;
        }
        hp.len = k;
        for (int i = 1; i <= k / 2; ++i)
            hp.sift(i);
        while (tm > 0 && hp.a[1].fish > 0) {
            ans += hp.a[1].fish;
            hp.a[1].fish -= d[hp.a[1].lake];
            hp.sift(1);
            tm--;
        }
        if (ans > max) 
            max = ans;
        //cout << ans << endl;
    }
    cout << max << endl;
    return 0;
}