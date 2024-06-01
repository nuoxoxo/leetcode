class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        int res = 0;
        vector<bool> L(26, false), U(26, false);
        for (char c : word)
        {
            if (islower(c))
                L[c - 'a'] = true;
            else
                U[c - 'A'] = true;
        }
        int i = -1;
        while (++i < 26)
            if (L[i] && U[i])
                ++res;
        return res;
    }
};
