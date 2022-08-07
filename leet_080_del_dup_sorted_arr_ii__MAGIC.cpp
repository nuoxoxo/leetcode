class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = -1, k = 0;

        while (++i < nums.size())
        {
            if (k < 2 || nums[i] > nums[k - 2])
                nums[k++] = nums[i] ;
        }
        return k ;
    }
};
