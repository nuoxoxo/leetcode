class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        vector<int> check, temp;
        int         i, res;

        check = count_n(n);
        i = 0;
        res = 0;
        while (res < (int) 1e9 + 1)
        {
            res = pow(2, i);
            temp = count_n(res);
            if (check == temp)
                return true;
            i++;
        }
        return false;
    }

    vector<int> count_n(int n)
    {
        vector<int> r(10, 0);

        while (n)
        {
            r[n % 10]++;
            n /= 10;
        }
        return r;
    }
};
