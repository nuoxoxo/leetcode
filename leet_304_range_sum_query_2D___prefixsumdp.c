


typedef struct
{
    int **grid, R;
} NumMatrix;


NumMatrix* numMatrixCreate(int** m, int r, int* c)
{
    if (!m || !r || !c)
        return NULL;

    NumMatrix   *res;
    int         **g, i, j;

    res = malloc(sizeof(NumMatrix));
    if (!res)
        return NULL;
    g = (int**) malloc(sizeof(int*) * (r + 1));
    if (!g)
        return NULL;    
    i = -1;
    while (++i < r + 1)
    {
        if (!(g[i] = (int*) malloc(sizeof(int) * ((*c) + 1))))
            return NULL;
        j = -1;
        while (++j < (*c) + 1)
            g[i][j] = 0;
    }
    i = -1;
    while (++i < r)
    {
        int prefix = 0;
        j = -1;
        while (++j < *c)
        {
            int above = g[i][j + 1];
            prefix += m[i][j];
            g[i + 1][j + 1] = prefix + above;
        }
    }
    res->grid = g;
    res->R = r;
    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int r1, int c1, int r2, int c2)
{
    if (!obj)
        return 0;
    int **g = obj->grid;
    int self = g[r1][c1];
    int U = g[r1][c2 + 1];
    int L = g[r2 + 1][c1];
    int DR = g[r2 + 1][c2 + 1];
    return self - U - L + DR;
}

void numMatrixFree(NumMatrix* obj)
{
    if (!obj)
        return ;

    int i = -1;
    while (++i < obj->R)
        free(obj->grid[i]);

    free(obj->grid);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
