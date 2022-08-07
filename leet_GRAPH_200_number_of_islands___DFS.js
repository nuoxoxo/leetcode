var numIslands = function(grid) {
    let c = grid[0].length
    let r = grid.length
    let res = 0
    let x = -1

    function DFS(grid, x, y, r, c){
        if (x < 0 || y < 0 || x > r - 1 || y > c - 1 || grid[x][y] != '1')
            return
        grid[x][y] = ' '
        DFS( grid, x + 1, y, r, c );
        DFS( grid, x - 1, y, r, c );
        DFS( grid, x, y + 1, r, c );
        DFS( grid, x, y - 1, r, c );
    }

    while (++x < r){
        let y = -1
        while (++y < c){
            if (grid[x][y] == '1'){
                res += 1
                DFS(grid, x, y, r, c)
            }
        }
    }
    return res
};


