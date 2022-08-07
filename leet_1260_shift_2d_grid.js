/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {
    r=grid.length
    c=grid[0].length
    a=r*c
    k%=a
    if(k==0)
        return grid
    res=[...Array(r)].map(e=>Array(c).fill(0))
    i=-1
    while (++i<r) {
        j=-1
        while (++j<c) {
            index = (i * c + j + k) % a
            di=Math.floor(index/c)
            dj=index%c
            res[di][dj]=grid[i][j]
        }
    }
    return res
};
