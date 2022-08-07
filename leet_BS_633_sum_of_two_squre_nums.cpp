class Solution {

#define ll long long

public:
    bool judgeSquareSum(int c) {
        ll  b = sqrt(c);
        ll  a = 0;
        while (a <= b)
        {
            ll  p = a * a + b * b;
            if (p == c)
                return true;
            if (p > c)
                --b;
            else
                ++a;
        }
        return false;
    }
};

/// test
/// 15248456
