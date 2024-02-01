class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string cp(s);
        reverse(cp.begin(), cp.end());
        int i = -1;
        string res;
        while (++i < s.length())
            res += min(s[i], cp[i]);
        return res;
    }
};
