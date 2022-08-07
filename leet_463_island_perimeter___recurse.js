/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    c = grid[0].length
    r = grid.length
    res = 0
    i = -1
    while (++i < r) {
        j = -1
        while (++j < c) {
            if (grid[i][j] == 1)
                res += 4 - countNeighbors(i, j, grid)
        }
    }
    return res
};

function    oneNeighbor(x, y, grid) {
    if (x == grid.length || y == grid[0].length || x == -1 || y == -1)
        return 0
    return grid[x][y]
}

function    countNeighbors(x, y, grid) {
    return oneNeighbor(x + 1, y, grid) + oneNeighbor(x - 1, y, grid) + 
        oneNeighbor(x, y + 1, grid) + oneNeighbor(x, y - 1, grid)
}
