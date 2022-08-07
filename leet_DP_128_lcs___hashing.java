class Solution {
    public int longestConsecutive(int[] n)
    {
        int     res, len, t, i;
        int[]   dp;
        
        len = n.length;
        if (len < 2)
            return len;
        dp = new int[len];
        Arrays.fill(dp, 1);
        Arrays.sort(n);
        i = 0;
        while (++i < len) {
            t = n[i] - n[i - 1];
            if (t < 2)
                dp[i] = dp[i - 1] + t;
        }
        res = 0;
        i = -1;
        while (++i < len)
            res = res > dp[i] ? res : dp[i];
        return res;
    }
}
