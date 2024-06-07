class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> D;
        for (char c : s)
            D[c]++;
        auto p = begin(D);
        int res = 0;
        int odd = 0;
        while (p != end(D))
        {
            int n = p->second;
            if (n % 2)
            {
                res += n - 1;
                odd = 1;
            }
            else
            {
                res += n;
            }
            p++;
        }
        if (odd)
            return res + 1;
        return res;
    }
};
