class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(26, false);
        vector<int> count(26, 0);
        string res;
        int a = 'a';
        for (char c: s)
            ++count[c - a];
        for (char c: s)
        {
            if (!seen[c - a])
            {
                while (res != "" && res.back() > c && count[res.back() - a] > 1)
                {
                    seen[res.back() - a] = false;
                    count[res.back() - a]--;
                    res.pop_back();
                }
                seen[c - a] = true;
                res += c;
            }
            else
                count[c - a]--;
        }
        return res;
    }
};
