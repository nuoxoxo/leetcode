class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> res;
        int         n, i;
        
        n = nums.size();
        k %= n;
        if (!k)
            return;
        i = n - k - 1;
        while (++i < n)
            res.push_back(nums[i]);
        i = -1;
        while (++i < n - k)
            res.push_back(nums[i]);
        nums = res;
    }
};
