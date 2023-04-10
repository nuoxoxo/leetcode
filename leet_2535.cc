class Solution {
public:
    int differenceOfSum(vector<int>& nums)
    {
        int r1 = 0;
        int r2 = 0;
        for (int n: nums)
        {
            r1 += n;
            r2 += digitsum(n);
        }
        int diff = r1 - r2;
        return diff < 0 ? -diff : diff;
    }

    int digitsum(int n)
    {
        int r = 0;
        while (n)
        {
            r += n % 10;
            n /= 10;
        }
        return r;
    }
};
