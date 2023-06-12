class Solution {
    public boolean searchMatrix(int[][] matrix, int target)
    {
        int     val;
        int     i = 0;
        int     j = matrix[0].length - 1;

        while (i < matrix.length && j > -1)
        {
            val = matrix[i][j];
            if (val < target)
                i++;
            else if (val > target)
                j--;
            else
                return true;
        }
        return false;
    }
}
