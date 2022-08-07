class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        int res = 0, i, j;
        vector<vector<int>> count(n, vector<int>(26, 0));

        i = -1;
        while (++i < n)
        {
            for (char c: words[i])
                count[i][c - 'a']++;
            j = -1;
            while (++j < i)
                if (cmp(count[i], count[j]))
                    res = max((int) words[i].length() * (int) words[j].length(), res);
        }
        return res;
    }

    int cmp(vector<int>& a, vector<int>& b) // using & is faster
    {
        int i = -1;
        while (++i < 26)
            if (a[i] && b[i])
                return false;
        return true;
    }
};
