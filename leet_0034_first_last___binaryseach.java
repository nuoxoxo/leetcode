class Solution {
    public int[] searchRange(int[] nums, int target)
    {
        int     mid, i, j;
        int[]   res;

        res = new int[2];
        res[0] = -1;
        res[1] = -1;
        i = 0;
        j = nums.length - 1;
        while (i <= j)
        {
            mid = (j - i) / 2 + i;
            if (nums[mid] == target)
            {
                i = j = mid;
                while (i > -1 && nums[i] == target)
                    --i;
                while (j < nums.length && nums[j] == target)
                    ++j;
                res[0] = i + 1;
                res[1] = j - 1;
                return res;
            }
            else if (nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return res;

    }
}
