class Solution {
public:
    int firstUniqChar(string s)
    {
        vector<int> E(26, 0);
        int         i = -1;
        while (++ i < s.length())
            E[s[i] - 'a'] ++ ;
        i = -1;
        while (++ i < s.length())
            if (E[s[i] - 'a'] == 1) return i ;
        return -1 ;
    }
};
