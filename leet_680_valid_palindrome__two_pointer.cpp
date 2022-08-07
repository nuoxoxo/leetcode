class Solution {
public:
    bool validPalindrome(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                string  L = s.substr(i, j - i);
                string  R = s.substr(i + 1, j - i);
                return (L == string(L.rbegin(), L.rend()) ||
                       R == string(R.rbegin(), R.rend()));
            }
            ++i;
            --j;
        }
        return true;
    }
};
