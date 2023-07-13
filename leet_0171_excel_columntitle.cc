class Solution {
public:
    int titleToNumber(string title)
    {
        int res = 0 ;
        for (char c: title) res = c - 64 + res * 26 ;
        return res ;
    }
};
