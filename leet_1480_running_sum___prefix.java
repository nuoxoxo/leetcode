class Solution {
    public int[] runningSum(int[] nums)
    {
        int n = nums.length;
        int i = 0;
        while (++i < n)
            nums[i] = nums[i] + nums[i - 1];
        return nums;
    }
}
