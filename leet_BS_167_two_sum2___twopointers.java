class Solution {
    public int[] twoSum(int[] n, int t) {
        int[]   res = new int[2];
        int     r = n.length - 1;
        int     i = 0;
        if (r != 1)
        {
            while (i < r)
            {
                int tt = n[i] + n[r];
                if (tt == t)
                    break;
                if (tt < t)
                    ++i;
                else
                    --r;
            }
        }
        res[0] = i + 1;
        res[1] = r + 1;
        return res;
    }
}
