

void    bubblesort(int *, int);

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
            g[i * side + j] = matrix[i][j];
    }
    bubblesort(g, side * side);
    return (g[k - 1]);
}

void    bubblesort(int *g, int side)
{
    int         counter, tmp, i, j;

    counter = -1;
    while (counter)
    {
        counter = 0;
        i = -1;
        while (++i < side - 1)
        {
            j = -1;
            while (++j < side - i - 1)
            {
                if (g[j] > g[j + 1])
                {
                    counter ++;
                    tmp = g[j];
                    g[j] = g[j + 1];
                    g[j + 1] = tmp;
                }
            }
        }
    }
}
