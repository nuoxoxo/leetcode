class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int len = s1.size();
        vector<vector<int>> a(len + 1, vector<int>(len + 1, 0));
        int i = 0, j;
        while (++i < len + 1)
        {
            j = 0;
            while (++j < len + 1)
            {
                if (s1[i - 1] == s2[j - 1])
                    a[i][j] = a[i - 1][j - 1] + 1;
                else
                    a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
        return a[len][len];
    }
};
