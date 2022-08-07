class Solution {
    public int[] runningSum(int[] nums)
    {
        int     size = nums.length;
        int     res[] = new int[size];
        int     run = 0;
        int     i = -1;

        Arrays.fill(res, 0);
        while (++i < size)
        {
            run += nums[i];
            res[i] = run;
        }
        return res;
    }
}
