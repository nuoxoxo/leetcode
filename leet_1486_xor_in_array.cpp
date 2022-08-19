class Solution {
public:
    int xorOperation(int n, int start)
    {
        int i = -1, tmp, res;

        while (++i < n)
        {
            tmp = start + 2 * i;
            if (!i)
                res = tmp;
            else
                res ^= tmp;
        }
        return res;
    }
};
