// Leetcode 2824 : 
//  Solution : Sliding window
class Solution {
public:
    int countPairs(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int L = 0, R = (int) nums.size() - 1;
        while (L < R)
        {
            if (nums[L] + nums[R] < target)
            {
                res += R - L;
                ++L;
            }
            else
            {
                --R;
            }
        }
        return res;
    }
};
