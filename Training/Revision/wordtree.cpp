#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    string word[8010];
    int ans = 0, n = 0;
    while (cin >> word[n])
        n++;
    
    sort(word, word + n);
    
    for (int i = 0; i < n; ++i) {
        int p;
        for (p = 0; p < word[i].length() && p < word[i - 1].length(); ++p) {
            if (word[i][p] != word[i - 1][p])
                break;
	        }
            ans += (int)word[i].length() - p;
    }
    cout << ans + 1 << endl;
    return 0;
}