func maxIncreaseKeepingSkyline(grid [][]int) int {
    N := len(grid)
    // assert N == len(grid[0])
    res := 0
    var r, c int
    R := make([]int, N)
    C := make([]int, N)
    r = 0
    for r < N {
        R[r] = 0
        C[r] = 0
        r++
    }
    r = 0
    for r < N {
        // fmt.Println(r, c, N)
        c = 0
        for c < N {
            n := grid[r][c]
            if R[r] < n {
                R[r] = n
            }
            if C[c] < n {
                C[c] = n
            }
            c++
        }
        r++
    }
    r = 0
    for r < N {
        c = 0
        for c < N {
            max_tolerance := R[r]
            if R[r] > C[c] {
                max_tolerance = C[c]
            }
            diff := max_tolerance - grid[r][c]
            if diff > 0 {
                res += diff
            }
            c++
        }
        r++
    }
    return res
}
