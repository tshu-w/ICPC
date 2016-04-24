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

int main(int argc, char const *argv[])
{
	set<string> dict;
	string line, word;
	while(getline(cin, line)) {
		for (int i = 0; i < line.size(); ++i)
			if (isalpha(line[i]))
				line[i] = tolower(line[i]);
			else 
				line[i] = ' ';
		stringstream ss(line);
		while (ss >> word) {
			dict.insert(word);
		}
	}
	set<string>::iterator it;
	for (it = dict.begin(); it != dict.end(); ++it) 
		cout << *it << endl;
	return 0;
}