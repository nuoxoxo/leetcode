class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        int     n = (int) word1.length();
        int     i = -1;
        char    c, cc;
        
        unordered_set<int>  s1, s2;
        vector<int>         v1(26, 0), v2(26, 0);
        
        if (n ^ (int) word2.length())
            return false;
        while (++i < n)
        {
            c = word1[i];
            cc = word2[i];
            s1.insert(c);
            s2.insert(cc);
            ++v1[c - 'a'];
            ++v2[cc - 'a'];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return (s1 == s2 && v1 == v2);
    }
};

