class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        vector<int> res(nums.size());
        int i = -1, j;

        while (++i < nums.size())
        {
            for (int n : nums)
                if (n < nums[i])
                    res[i]++;
        }
        return res;
    }
};
