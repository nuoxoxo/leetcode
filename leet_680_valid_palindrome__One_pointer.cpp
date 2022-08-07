class Solution {
public:
    bool validPalindrome(string s)
    {
        int n = s.length();
        int i = 0;
        while (i < n / 2)
        {
            if (s[i] != s[n - 1 - i])
            {
                string  left = s.substr(i + 1, n - i - 1 - i);
                string  right = s.substr(i, n - i - 1 - i);
                if (left != string(left.rbegin(), left.rend()) &&
                   right != string(right.rbegin(), right.rend()))
                    return false;
                else
                    return true;
            }
            ++i;
        }
        return true;
    }
};
