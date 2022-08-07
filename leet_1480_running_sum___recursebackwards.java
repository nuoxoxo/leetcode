class Solution {
    public int[] runningSum(int[] nums)
    {
        return recurse(nums, nums.length - 1);
    }

    public int[]    recurse(int[] nums, int i)
    {
        if (i != 0)
        {
            recurse(nums, i - 1);
            nums[i] += nums[i - 1];
        }
        return nums;
    }
}
