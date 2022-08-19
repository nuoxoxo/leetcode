class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums)
    {
        vector<int> res;
        int i = 0, j;

        while (i < nums.size())
        {
            j = 0;
            while (j < nums[i])
            {
                res.push_back(nums[i + 1]);
                ++j;
            }
            i += 2;
        }
        return res;
    }
};
