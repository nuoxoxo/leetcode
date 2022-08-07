

int     cmp(int *a, int *b);

int kthSmallest(int** matrix, int side, int* matrixColSize, int k)
{
    int         *g;
    int         i, j;

    g = malloc((side *side) * sizeof(int));
    i = -1;
    while (++i < side)
    {
        j = -1;
        while (++j < side)
        {
            g[i * side + j] = matrix[i][j];
            // printf("%d ", g[i * side + j]);
        }
    }
    qsort(g, side * side, sizeof(int), & cmp);
    /*
    i = -1;
    while (++i < side * side)
        printf("%d ", g[i]);
    */
    return (g[k - 1]);
}

int     cmp(int *a, int *b)
{
    return (*a - *b);
}
