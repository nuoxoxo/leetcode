class Solution {
    public List<List<Integer>> generate(int n)
    {
        List<List<Integer>>     dp = new ArrayList<>();
        int                     i= -1, num;

        while (++i < n)
        {
            int             j = -1;
            List<Integer>   temp = new ArrayList<>();
            while (++j < i + 1)
            {
                if (j == 0 || j == i)
                    temp.add(1);
                else
                {
                    num = dp.get(i - 1).get(j - 1) + dp.get(i - 1).get(j);
                    temp.add(num);
                }
            }
            dp.add(temp);
        }
        return dp;
    }
}
