class Solution {
public:
    string longestPalindrome(string s) {
        string ss = "#";
        for (auto ch : s) {
            ss += ch; ss += "#";
        }

        int maxRight = 0, centor = 0;
        string ans;
        int maxLen = 0;
        vector<int> p(ss.size(), 0);
        for (int i = 0; i < ss.size(); i++) {
            if (maxRight > i) {
                int mirror = 2 * centor - i;
                p[i] = min(p[mirror], maxRight - i);
            }
            while (i - (p[i] + 1) >= 0 && i + p[i] + 1 < ss.size() && ss[i - (p[i] + 1)] == ss[i + (p[i] + 1)])
                p[i]++;

            if (p[i] > maxLen) {
                ans = ss.substr(i - p[i], p[i] * 2 + 1);
                maxLen = p[i];
            }

            if (i + p[i] > maxRight) {
                centor = i;
                maxRight = i + p[i];
            }
        }

        ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
        return ans;
    }
};
