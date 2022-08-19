class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0, res = 0;

        for (char c : s)
        {
            if (c == 'R')
                cnt++;
            else
                cnt--;
            res += !cnt;
        }
        return res; 
    }
};
