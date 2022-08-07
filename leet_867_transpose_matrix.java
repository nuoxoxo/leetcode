class Solution {
    public int[][] transpose(int[][] matrix)
    {
        int     C = matrix[0].length;
        int     R = matrix.length;
        int[][] m = new int[C][R];
        int     r, c = -1;

        while (++c < C)
        {
            r = -1;
            while (++r < R)
                m[c][r] = matrix[r][c];
        }
        return m;
    }
}
