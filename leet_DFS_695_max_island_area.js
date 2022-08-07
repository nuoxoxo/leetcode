/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let c = grid[0].length
    let r = grid.length
    let res = 0
    let i = -1
    while (++i < r){
        let j = -1
        while (++j < c){
            if (grid[i][j] == 1){
                let tmp = DFS(grid,i,j)
                res = Math.max(res, tmp)
            }
        }
    }
    return res
    
};

function DFS(grid, i, j){
    let res = 0
    if (i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1 || grid[i][j] != 1){
        return res
    }
    grid[i][j] = 0
    res += 1 + DFS(grid,i+1,j) + DFS(grid,i-1,j) + DFS(grid,i,j+1) + DFS(grid,i,j-1)
    return res
}
