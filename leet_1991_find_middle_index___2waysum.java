class Solution {
    public int findMiddleIndex(int[] nums)
    {
        int     total;
        int     right;
        int     left;
        int     i;
        int     n;

        i = -1;
        total = 0;
        n = nums.length;
        while (++i < n)
            total += nums[i];
        right = 0;
        left = 0;
        i = -1;
        while (++i < n)
        {
            right = total - nums[i] - left;
            if (left == right)
                return (i);
            left += nums[i];
        }
        return (-1);
    }
}
