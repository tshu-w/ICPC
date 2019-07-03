// written at 11:15 on 24 May 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "1597"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

/* RE
typedef vector<string> article;
typedef vector<article > articles;

typedef struct SA {
    vector<set<string> > sentence;
    set<string> articles;
} sa;
typedef vector<sa> sarticles;

int n, m;
string s;
articles A(110);
sarticles B(110);

int main(void) {
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (getline(cin, s) && s[0] != '*') {
            A[i].push_back(s);

            for (int j = 0; j < (int)s.size(); j++) {
                s[j] = tolower(s[j]);
                if (!isalnum(s[j])) s[j] = ' ';
            }

            B[i].sentence.push_back(set<string>());
            stringstream ss(s);
            string word;
            while (ss >> word) {
                B[i].articles.insert(word);
                B[i].sentence[cnt].insert(word);
            }
            cnt++;
        }
    }

    cin >> m;
    getline(cin, s);
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        if (s.find("AND") != string::npos) {
            stringstream ss(s);
            string s1, s2, s3;
            ss >> s1 >> s3 >> s2;
            for (int j = 0; j < (int)s.size(); j++) s1[j] = tolower(s1[j]);
            for (int j = 0; j < (int)s.size(); j++) s2[j] = tolower(s2[j]);

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (B[j].articles.count(s1) && B[j].articles.count(s2)) {
                    if (!flag) cout << "----------\n";
                    for (int k = 0; k < (int)A[j].size(); k++)
                        if (B[j].sentence[k].count(s1) || B[j].sentence[k].count(s2))
                            cout << A[j][k] << "\n";
                    flag = false;
                }
            }
            if (flag) cout << "Sorry, I found nothing.\n";
        }
        else if (s.find("OR") != string::npos) {
            stringstream ss(s);
            string s1, s2, s3;
            ss >> s1 >> s3 >> s2;
            for (int j = 0; j < (int)s.size(); j++) s1[j] = tolower(s1[j]);
            for (int j = 0; j < (int)s.size(); j++) s2[j] = tolower(s2[j]);

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (B[j].articles.count(s1) || B[j].articles.count(s2)) {
                    if (!flag) cout << "----------\n";
                    for (int k = 0; k < (int)A[j].size(); k++)
                        if (B[j].sentence[k].count(s1) || B[j].sentence[k].count(s2))
                            cout << A[j][k] << "\n";
                    flag = false;
                }
            }
            if (flag) cout << "Sorry, I found nothing.\n";
        }
        else if (s.find("NO") != string::npos) {
            stringstream ss(s);
            string s1, s2;
            ss >> s2 >> s1;
            for (int j = 0; j < (int)s.size(); j++) s1[j] = tolower(s1[j]);

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (B[j].articles.count(s1) == 0) {
                    if (!flag) cout << "----------\n";
                    for (int k = 0; k < (int)A[j].size(); k++)
                        cout << A[j][k] << "\n";
                    flag = false;
                }
            }
            if (flag) cout << "Sorry, I found nothing.\n";
        }
        else {
            for (int j = 0; j < (int)s.size(); j++) s[j] = tolower(s[j]);

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (B[j].articles.count(s)) {
                    if (!flag) cout << "----------\n";
                    for (int k = 0; k < (int)A[j].size(); k++)
                        if (B[j].sentence[k].count(s))
                            cout << A[j][k] << "\n";
                    flag = false;
                }
            }
            if (flag) cout << "Sorry, I found nothing.\n";
        }
        cout << "==========\n";
    }
    return 0;
}
*/
