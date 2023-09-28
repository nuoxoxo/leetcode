class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = (int) nums.size();
        int j = n - 1;
        int i = 0;
        while (i < j)
        {
            while (i < j && nums[i] % 2 == 0)
                ++i;
            while (i < j && nums[j] % 2)
                --j;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            //  or swap( nums[i] , nums[j] ) ;
        }
        return nums;
    }
};
