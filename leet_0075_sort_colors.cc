class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int len = nums.size() ;

        if (len < 2)
            return ;
        if (len == 2)
        {
            if (nums[0] > nums[1])
                swap(nums[0], nums[1]) ;
            return ;
        }

        int i = 0, j = len - 1, k ;

        while (!nums[i])
            ++ i ;
        while (nums[j] == 2)
            -- j ;
        k = i - 1;
        while (++k <= j)
        {
            if (!nums[k])
            {
                nums[k] = nums[i];
                nums[i++] = 0;
            }
            else if (nums[k] == 2)
            {
                nums[k] = nums[j];
                nums[j--] = 2;
                k--;
            }
        }
    }
};
