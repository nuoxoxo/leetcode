class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0, res = 0;

        for (char c : s)
        {
            if (c == 'R')
                cnt++;
            if (c == 'L')
                cnt--;
            if (!cnt)
                res++;
        }
        return res; 
    }
};
