int islandPerimeter(int** grid, int gridSize, int* gridColSize) {

    int R = gridSize, C = gridColSize[0];
    int res = 0;
    int r = -1, c;
    while (++r < R)
    {
        c = -1;
        while (++c < C)
        {
            if (grid[r][c] == 1)
            {
                res += 4;
                if (r > 0 && grid[r - 1][c] == 1)
                    res -= 2;
                if (c > 0 && grid[r][c - 1] == 1)
                    res -= 2;
            }
        }
    }
    return res;
}
