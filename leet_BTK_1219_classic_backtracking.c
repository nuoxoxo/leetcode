int go(int, int, int, int, int, int**);

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {

    int R = gridSize;
    int C = *gridColSize;
    // printf("%d %d", R, C);

    int r = -1, c;
    int res = 0;
    while (++r < R)
    {
        c = -1;
        while (++c < C)
        {
            if (grid[r][c] < 1)
                continue ;
            int temp = go(r, c, 0, R, C, grid);
            res = res > temp ? res : temp;
        }
    }

    return res;
}

int go(int r, int c, int curr, int R, int C, int **G)
{
    if (r < 0 || r > R - 1 || c < 0 || c > C - 1 || G[r][c] < 1)
        return curr;
    int gold = G[r][c];
    G[r][c] = 0;
    curr += gold;
    int a = go(r - 1, c, curr, R, C, G);
    int b = go(r + 1, c, curr, R, C, G);
    int x = go(r, c - 1, curr, R, C, G);
    int y = go(r, c + 1, curr, R, C, G);
    int res = a;
    if (res < b)
        res = b;
    if (res < x)
        res = x;
    if (res < y)
        res = y;
    G[r][c] = gold;
    return res;
}
