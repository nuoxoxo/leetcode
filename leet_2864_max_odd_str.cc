class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        string res;
        int one = 0;
        for (char c: s)
            if (c == '1') ++one;
        int zero = s.length() - one;
        int i = 0;
        while (++i < one) res += '1';
        i = -1;
        while (++i < zero) res += '0';
        return res + '1';
    }
};
