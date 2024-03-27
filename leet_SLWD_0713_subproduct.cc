class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        vector<int(*)(vector<int> &, int)> Solutions {
            Two_pointers,
        };
        return Solutions[0](nums, k);
    }

    static int Two_pointers(vector<int>& nums, int k)
    {
        if (k < 2)
            return 0;
        int res = 0;
        int prod = 1;
        int R = -1;
        int L = 0;
        while (++R < nums.size())
        {
            prod *= nums[ R ];
            while (prod >= k)
            {
                prod /= nums[ L ];
                ++L;
            }
            res += R - L + 1;
        }
        return res;
    }
};
