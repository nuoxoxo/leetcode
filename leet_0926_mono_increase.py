/*
"0101100011"
*/

class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int len = s.length();
        int one = 0, zero = 0;
        for (char & c: s)
        {
            if (c == '1')
                one++;
            if (c == '0')
                zero++;
            zero = min(one, zero);
        }
        return zero;
    }
};
