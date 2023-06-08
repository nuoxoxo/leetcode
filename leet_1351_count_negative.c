int countNegatives(int** g, int gridSize, int* gridColSize)
{
    int res = 0;
    int R = gridSize;
    int C = *gridColSize;
    int r = 0;
    int c = C - 1;
    while (r < R && c > -1)
    {
        if (g[r][c] < 0)
        {
            res += R - r;
            --c;
        }
        else
        {
            ++r;
        }
    }
    return res ;
}

/*
[
    [ 4, 3, 2,-1],
    [ 3, 2, 1,-1],
    [ 1, 1,-1,-2],
    [-1,-1,-2,-3]
]
*/
