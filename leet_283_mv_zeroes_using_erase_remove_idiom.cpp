class Solution {
public:

    //  using the erase-remove idiom

    void moveZeroes(vector<int>& nums)
    {
        int size, i;

        size = nums.size();
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        size -= nums.size();
        while (size)
        {
            nums.push_back(0);
            size --;
        }
    }
};
