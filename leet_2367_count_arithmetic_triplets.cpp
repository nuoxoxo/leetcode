class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int i = -1, r = 0, n;

        while (++i < nums.size())
        {
            n = nums[i];
            if (find(nums.begin() + i, nums.end(), n + diff) != nums.end() &&
               find(nums.begin() + i, nums.end(), n + 2 * diff) != nums.end())
                r++;
        }
        return r;
    }
};
