class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = (int) nums.size() - 1;
        int res = 1; // see constraints

        while (l < r)
        {
            res = max(nums[l] + nums[r], res);
            ++l;
            --r;
        }
        return res;

        // old soln

        /*
        sort(nums.begin(), nums.end());
        int len = (int) nums.size();
        int res = -2147483648;
        int i = -1;
        while (++i < len / 2)
            res = max(nums[i] + nums[len - i - 1], res);
        return res;
        */
    }
};
