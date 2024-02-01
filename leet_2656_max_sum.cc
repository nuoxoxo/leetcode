class Solution {
public:
    int maximizeSum(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums[0];
        int i = -1;
        int res = 0;
        while (++i < k)
        {
            res += n;
            n++;
        }
        return res;
    }
};
