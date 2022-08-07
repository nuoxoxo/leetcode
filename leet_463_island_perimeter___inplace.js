/**
 * @param {number[][]} grid
 * @return {number}
 */

var islandPerimeter = function(grid)
{
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    c = grid[0].length
    r = grid.length
    tt = 0
    x = -1
    while (++x < r) {
        y = -1
        while (++y < c) {
            if (grid[x][y] == 1) {
                n = 4
                while (--n > -1) {
                    i = x + dx[n]
                    j = y + dy[n]
                    if (i == r || i < 0 || j < 0 || j == c || grid[i][j] == 0)
                        ++tt
                }
            }
        }
    }
    return tt
};
