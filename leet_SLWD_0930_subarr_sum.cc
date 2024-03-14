class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int N = (int) nums.size();
        if (N == 1)
            return nums[0] == goal;
        int temp = 0, l = 0, G = 0;
        int r = -1;
        while (++r < N)
        {
            temp += nums[r];
            while (temp > goal)
                temp -= nums[l++];
            G += r - l + 1;
        }
        if (goal == 0)
            return G;
        temp = 0;
        l = 0;
        r = -1;
        int Gminus1 = 0;
        while (++r < N)
        {
            temp += nums[r];
            while (temp > goal - 1)
                temp -= nums[l++];
            Gminus1 += r - l + 1;
        }
        return G - Gminus1;
    }
};
