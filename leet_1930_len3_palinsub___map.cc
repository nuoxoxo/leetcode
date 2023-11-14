class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<int, vector<int>> D;
        int len = (int) s.length();
        int i = -1;
        while (++i < len)
        {
            char c = s[i];
            if (D.contains(c))
                D[c][1] = i;
            else
                D[c] = {i, -1};
        }
        int res = 0;
        for (auto it: D)
        {
            // cout << it.first << ' ' << it.second.size() << '\n';
            char c = it.first;
            int l = it.second[0];
            int r = it.second[1];
            if (r == -1)
                continue ;
            unordered_set<char> S;
            i = l;
            while (++i < r)
                S.insert(s[i]);
            res += (int) S.size();
        }
        return res;
    }
};
