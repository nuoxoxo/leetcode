class Solution {
public:
    bool isPowerOfFour(int n)
    {
        double  r;

        if (n < 1)
            return false;
        r = log2(n) / 2;
        if (ceil(r) == floor(r))
            return true;
        return false;
    }
};
