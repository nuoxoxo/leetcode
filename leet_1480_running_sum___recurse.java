class Solution {
    public int[] runningSum(int[] nums)
    {
        return recurse(nums, 1);
    }

    public int[]    recurse(int[] nums, int i)
    {
        if (i == nums.length)
            return nums;
        nums[i] += nums[i - 1];
        return recurse(nums, i + 1);
    }
}
