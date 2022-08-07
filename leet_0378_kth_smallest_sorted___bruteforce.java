class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int     side = matrix.length, i = -1, j;
        int[]   g = new int[side * side];

        while (++i < side) {
            j = -1;
            while (++j < side)
                g[i * side + j] = matrix[i][j];
        }
        Arrays.sort(g);
        return g[k - 1];
    }
}
