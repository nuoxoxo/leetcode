class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int L = 0, R = num;
        while (L <= R)
        {
            unsigned long   mid = (R - L) / 2 + L;
            unsigned long   msq = mid * mid;
            if (msq == (unsigned long) num)
                return true;
            if (msq > (unsigned long) num)
                R = mid - 1;
            if (msq < (unsigned long) num)
                L = mid + 1;
        }
        return false;
    }
};
