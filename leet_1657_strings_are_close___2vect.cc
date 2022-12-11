class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        int     n = (int) word1.length();
        int     i, c, cc;
        
        // unordered_set<int>  s1, s2; // we can also use vectors
        
        vector<int>         vs1(26,0), vs2(26,0);
        vector<int>         v1(26, 0), v2(26, 0);
        
        if (n ^ (int) word2.length())
            return false;
        i = -1;
        while (++i < n)
        {
            c = word1[i] - 'a';
            cc = word2[i] - 'a';
            vs1[c] = 1;
            vs2[cc] = 1;
            ++v1[c];
            ++v2[cc];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        //return (s1.size() == s2.size() && v1 == v2);
        
        return (vs1 == vs2 && v1 == v2);
    }
};
