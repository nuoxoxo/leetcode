class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        int n = left;
        while (n < right + 1)
        {
            if (isSD(n))
                res.push_back(n);
            ++n;
        }
        return res;
    }

    bool isSD(int num)
    {
        int n = num;
        while (n)
        {
            int div = n % 10;
            if ( !div || num % div != 0)
                return false;
            n /= 10;
        }
        return true;
    }
};
