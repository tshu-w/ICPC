#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int size[500050], n, hide = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> size[i];
    }
    sort(size, size + n);
    int j = 0;
    for (int i = n / 2 + (n % 2); i < n; ++i) {
        //cout << i << ' ' << j << '    ';
        if (size[i] >= 2 * size[j]) {
            ++j;
            ++hide;
            //cout << size[i] << ' ' << size[j] << endl;
        }
    }
    cout << (n - hide) << endl;
    return 0;
}