class Solution {
    public int pivotIndex(int[] nums)
    {
        float   cur = 0;
        int     i = -1;
        int     s = 0;
        for (int n: nums)
            s += n;
        while (++i < nums.length)
        {
            if (i > 0)
                cur += nums[i - 1];
            if (cur == (s - n[i]) / 2)
                return i;
        }
        return -1;
    }
}
