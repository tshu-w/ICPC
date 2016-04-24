#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
const int maxn = 30010;
class Heap
{
public:
    Heap():len(0) {
        memset(a, 0, sizeof(a));
    };
    ~Heap() {};
    void put(int x);
    int get();
    int getlen();
private:
    int len;
    int a[maxn];
};
int Heap::getlen() {
    return len;
}
void Heap::put(int x) {
    a[++len] = x;
    int p = len;
    while (p != 1 && a[p] < a[p / 2]) {
        int tmp = a[p];
        a[p] = a[p / 2];
        a[p / 2] = tmp;
        p /= 2;
    }
    return ;
}
int Heap::get() {
    int num = a[1];
    a[1] = a[len--];
    int fa = 1, son = 0;
    while (fa * 2 <= len) {
        if (fa * 2 + 1 > len || a[fa * 2] < a[fa * 2 + 1])
            son = fa * 2;
        else
            son = fa * 2 + 1;
        if (a[fa] > a[son]) {
            int tmp = a[fa];
            a[fa] = a[son];
            a[son] = tmp;
            fa = son;
        }
        else
            break;
    }
    return num;
}
int main(int argc, char const *argv[])
{
    int n, ans(0);
    Heap hp;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        hp.put(x);
    }
    for (int i = 0; i < n - 1; ++i) {
        int m1 = hp.get();
        int m2 = hp.get();
        ans += m1 + m2;
        hp.put(m1 + m2);
    }
    cout << ans << endl;
    return 0;
}