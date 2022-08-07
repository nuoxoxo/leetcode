class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int len = arr.size(), res = 0, i = 0, j, tmp;

        while (i < arr.size())
        {
            j = 0 ;
            tmp = 0;
            while (i + j < len)
            {
                tmp += accumulate(arr.begin() + i, arr.begin() + i + j + 1, 0);
                j += 2;
            }
            res += tmp ;
            ++i ;
        }
        return res ;
    }
};
