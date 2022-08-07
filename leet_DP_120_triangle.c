

int minimumTotal(int** tg, int tgSize, int* tgColSize)
{
    int i = tgSize - 1;
    while (--i > -1)
    {
        int j = -1;
        while (++j < tgColSize[i])
        {
            int a = tg[i + 1][j];
            int b = tg[i + 1][j + 1];
            tg[i][j] += a < b ? a : b;
        }
    }
    return tg[0][0];
}
