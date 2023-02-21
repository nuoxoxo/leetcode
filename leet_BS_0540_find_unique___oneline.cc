class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        return (accumulate(nums.begin(), nums.end(), 0, std::bit_xor()));
    }
};
