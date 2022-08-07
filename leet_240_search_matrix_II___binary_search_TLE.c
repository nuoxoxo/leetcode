

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
        int     i = -1;
        int     L, mid, val, R;

        while (++i < matrixSize)
        {
            L = 0;
            R = *matrixColSize - 1;
            while (L <= R)
            {
                mid = (L + R) / 2;
                val = matrix[i][mid];
                if (val < target)
                    L++;
                else if (val > target)
                    R--;
                else
                    return true;
            }
        }
        return false;
}
