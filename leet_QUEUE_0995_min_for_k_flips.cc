class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k)
    {

        deque<int> Ends;
        int N = nums.size();
        bool flipping;
        int res = 0;
        int i = -1;
        while (++i < N)
        {
            if (Ends.size() && Ends.front() == i)
            {
                Ends.pop_front();
                flipping = !flipping;
            }
            if (nums[i] == flipping)
            {
                res++;
                Ends.push_back(i + k);
                flipping = !flipping;
            }
        }
        if (Ends.size() > 1)
            return -1;
        if (Ends.empty() || Ends[0] == N)
             return res;
        return -1;

        // [1,1,0], k = 2
        //   -> [1,0,1] -> we can flip these 2
        //         ^ ^ 
        //   -> [0,0,1] -> or we can flip these
        //       ^ ^ 
        //   -> impossible bc. a 0- or 1-bit is left either way
        //
        // [0,0,0,1,0,1,1,0], k = 3
        //   -> [1,1,1,1,0,1,1,0] -> step1
        //       ^ ^ ^ 
        //   -> [1,1,1,1,1,0,0,0] -> step2
        //               ^ ^ ^
        //   then flip the final len-3 subarr
        //
        //       Strategy
        // once we can flip we flip, store the window flipped, swicth state and gain 1
        // once we meet the R-index of a window, dispose this window, swich the state
        //
        //       Tool
        // a queue to store the window where flips happen.
        // a window is identified by the R-index of the window.
    }
};
