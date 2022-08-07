class Solution {
    public int minimumTotal(List<List<Integer>> t)
    {
        int i = t.size() - 1;
        while (--i > -1)
        {
            int j = -1;
            while (++j < t.get(i).size())
            {
                int a = t.get(i + 1).get(j);
                int b = t.get(i + 1).get(j + 1);
                int min = a < b ? a : b;
                int cur = t.get(i).get(j);
                t.get(i).set(j, cur + min);
            }
        }
        return t.get(0).get(0);
    }
}
