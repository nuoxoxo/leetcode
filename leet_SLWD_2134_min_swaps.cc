class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        int N = nums.size();
        // idea
        //  011100110
        //    ^^^^^  for any len-N window, we look for a min amount of 0's
        //  0101100
        //   ^^^ 

        // how many 1's
        int window = accumulate(begin(nums), end(nums), 0);
        int res = window; 
       
        int ones = 0;
        int R = -1;
        while (++R < N * 2)
        {
            int newR = R % N;
            if (nums[newR] == 1)
                ones++;
            if (R >= window)
            {
                int newL = (R - window) % N;
                if (nums[newL] == 1)
                    ones--;
            }
            res = min(res, window - ones);
        }
        return res;
    }
};
