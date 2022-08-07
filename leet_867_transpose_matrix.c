

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int **res, r, c, i;

    res = (int**) malloc(sizeof(int*) * (*matrixColSize));
    if (!res)
        return NULL;
    *returnColumnSizes = (int*) malloc(sizeof(int) * (*matrixColSize));
    if (!returnColumnSizes)
        return NULL;
    *returnSize = *matrixColSize;
    c = -1;
    while (++c < *matrixColSize)
    {
        int *tmp = (int*) malloc(sizeof(int) * matrixSize);
        if (!tmp)
            return NULL;
        (*returnColumnSizes)[c] = matrixSize;
        r = -1;
        i = -1;
        while (++r < matrixSize)
            tmp[++i] = matrix[r][c];
        res[c] = tmp;
    }
    return res;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
