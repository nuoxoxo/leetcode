

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int         temp, i, j;

    j = *matrixColSize - 1;
    i = 0;
    while (i < matrixSize && j > -1)
    {
        temp = matrix[i][j];
        if (temp < target)
            ++i;
        else if (temp > target)
            --j;
        else
            return true;
    }
    return false;
}
