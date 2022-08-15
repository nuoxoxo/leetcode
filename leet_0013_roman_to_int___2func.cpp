class Solution {
public:
    int romanToInt(string s)
    {
        int     self, next, res, len, i;

        len = (int) s.length();
        res = 0;
        i = 0;
        while (i < len)
        {
            self = bf(s[i]);
            next = i + 1 < len ? bf(s[i + 1]) : 0;    
            if (self < next) 
            {
                res += next - self;
                i += 1;
            }
            else
            {
                res += self; 
            }
            i += 1;
        }
        return res;
    }

    int     bf(char c) // bf = brute-force
    {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        if (c == 'M')
            return 1000;
        else
            return 0;
    }
};
