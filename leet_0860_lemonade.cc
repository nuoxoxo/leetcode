class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int p5 = 0, p10 = 0;
        for (int n: bills)
        {
            if (n == 5)
                ++p5;
            else if ( n == 20 && p5 && p10 )
            {
                --p10;
                --p5;
            }
            else if ( n == 20 && p5 > 2 )
                p5 -= 3;
            else if ( n == 10 && p5 )
            {
                --p5;
                ++p10;
            }
            else
                return false;
        }
        return true;
    }
};
