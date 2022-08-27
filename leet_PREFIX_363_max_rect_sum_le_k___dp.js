/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var maxSumSubmatrix = function(grid, k) {
    let c = grid[0].length
    let r = grid.length
    let i, j
    let dp = [...Array(r + 1)].map(e => Array(c).fill(0))
    // console.log(dp)
    i = -1;
    while (++i < r) {
        j = -1;
        while (++j < c)
            dp[i + 1][j] = dp[i][j] + grid[i][j];
    }
    // console.log(dp)
    let res = -2147483648;
    i = -1;
    while (++i < r) {
        let ii = i;
        while (++ii < r + 1) {
            j = -1;
            while (++j < c) {
                let tmp = 0;
                let jj = j - 1;
                while (++jj < c) {
                    tmp += dp[ii][jj] - dp[i][jj];
                    if (tmp == k)
                        return k;
                    if (tmp < k && res < tmp)
                        res = tmp;
                }
            }
        }
    }
    return res;
};

/*
[[1,0,1],[0,-2,3]]
2
[[2,2,-1]]
3
[[2,2,-1]]
0
[[1,0,1],[0,-2,3],[2,6,-6]]
2
[[1,0,1],[0,-2,3],[-10,-12,-1]]
2
*/
