class Solution {
    public int findDuplicate(int[] nums)
    {
        int n = nums.length;
        Arrays.sort(nums);
        if (n == 2)
        {
            return nums[0];
        }
        int i = 1;
        int j = n - 2;
        n /= 2;
        while (i != j && i < n && j > n)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
            if (nums[j] == nums[j + 1])
                return nums[j];
            i++;
            j--;
        }
        return nums[i];
    }
}
