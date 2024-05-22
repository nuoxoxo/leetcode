class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {
        /*
        [5,1,6]
            [5] -> 5
            [1] -> 1
            [6] -> 6
            [5,1] -> 5^1 = 4
            [5,6] -> 5^6 = 3
            [1,6] -> 1^6 = 7
            [5,1,6] -> 5^1^6 = 2
        total = 28
        */

        // basically bruteforce iteratively

        int res = 0;
        int N = nums.size();
        int mask = -1;
        while (++mask < (1 << N))
        {
            int temp = 0;
            int i = -1;
            while (++i < N)
            {
                // if (mask & (1 << i) > 0) // bug
                int curr = mask & (1 << i);
                if (curr > 0)
                    temp ^= nums[i];
            }
            res += temp;
        }
        return res;
    }
};
