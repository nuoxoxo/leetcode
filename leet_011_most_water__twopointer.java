class Solution {
    public int maxArea(int[] height)
    {
        int n = height.length;
        int p2 = n - 1;
        int p1 = 0;
        int res = 0, tmp;
        while (p1 < p2)
        {
            tmp = (p2 - p1) * Math.min(height[p1], height[p2]);
            res = Math.max(res, tmp);
            if (height[p1] < height[p2])
                ++p1;
            else
                --p2;
        }
        return res ;
    }
}
