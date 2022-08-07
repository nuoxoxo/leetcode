class Solution {
    public int chalkReplacer(int[] chalk, int k)
    {
        long    t = 0;
        int     n = chalk.length;
        int     i = 0;
        for (int c : chalk)
        {
            t += c;
        }
        k %= t;
        while (k > -1)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
            i += 1;
            i %= n;
        }
        return -1;
    }
}
