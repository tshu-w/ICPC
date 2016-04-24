#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;

const int INF = INT_MAX;
// const int MAX_N = ;
map<string, int> cnt;
vector<string> word;

string repr(const string &s) {
	string ss = s;
	for (int i = 0; i < ss.size(); ++i)
		ss[i] = tolower(ss[i]);
	sort(ss.begin(), ss.end());
	return ss;
}
int main(int argc, char const *argv[])
{
	string s;
	while (cin >> s) {
		if (s[0] == '#') 
			break;
		word.push_back(s);
		string ss = repr(s);
		if (!cnt.count(ss)) cnt[ss] = 0;
		++cnt[ss];
	}
	set<string> ans;
	for (int i = 0; i < word.size(); ++i)
		if (cnt[repr(word[i])] == 1) ans.insert(word[i]);
	set<string>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it) 
		cout << *it << endl;
	return 0;
}