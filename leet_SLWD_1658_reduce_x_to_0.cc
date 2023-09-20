class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tt = 0;
        for (int n : nums)
            tt += n;
        int Max = -1;
        int curr = 0;
        int l = 0;
        int r = -1;
        while (++r < (int) nums.size())
        {
            curr += nums[r];
            while (l <= r && curr > tt - x)
                curr -= nums[l++];
            if (curr == tt - x)
                Max = max(Max, r - l + 1);
        }
        if (Max < 0)
            return -1;
        return nums.size() - Max;
    }
};
