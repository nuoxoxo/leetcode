class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList)
    {
        // int[][] res = {};
        ArrayList<int[]>    res = new ArrayList<>();

        int n1 = firstList.length;
        int n2 = secondList.length;
        int i = 0, j = 0, hi, lo;

        while (i < n1 && j < n2)
        {
            lo = Math.max(firstList[i][0], secondList[j][0]);
            hi = Math.min(firstList[i][1], secondList[j][1]);
            if (lo <= hi)
                res.add( new int[] {lo, hi} );
            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }
        return res.toArray(new int[res.size()][2]);
    }
}
