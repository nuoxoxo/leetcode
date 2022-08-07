class Solution {
    public int findLHS(int[] nums)
    {
        HashMap<Integer, Integer>   mp;
        int                         size, res, tmp, n, i;

        mp = new HashMap<Integer, Integer>();
        size = nums.length;
        i = -1;
        while (++i < size)
        {
            n = nums[i];
            if (mp.containsKey(n))
                mp.put(n, mp.get(n) + 1);
            else
                mp.put(n, 1);
        }
        i = -1;
        res = 0;
        while (++i < size)
        {
            n = nums[i];
            if (mp.containsKey(n) && mp.containsKey(n + 1))
            {
                tmp = mp.get(n) + mp.get(n + 1);
                res = res > tmp ? res : tmp;
            }
        }
        return res;
    }
}
