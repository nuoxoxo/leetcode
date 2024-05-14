func getMaximumGold(grid [][]int) int {

    R := len(grid)
    C := len(grid[0])

    var backtrack func(int, int, int) int
    backtrack = func(r int, c int, curr int) int {
        if r < 0 || r > R - 1 || c < 0 || c > C - 1 || grid[r][c] < 1 {
            return curr
        }
        temp := grid[r][c]
        grid[r][c] = 0
        curr += temp
        a := backtrack(r + 1, c, curr)
        b := backtrack(r - 1, c, curr)
        x := backtrack(r, c + 1, curr)
        y := backtrack(r, c - 1, curr)
        if a < b {a = b}
        if a < x {a = x}
        if a < y {a = y}
        grid[r][c] = temp
        return a        
    }

    res := 0
    for r := range grid {
        for c := range grid[r] {
            if grid[r][c] < 1 {
                continue
            }
            temp := backtrack(r, c, 0)
            if res < temp {
                res = temp
            }
        }
    }
    return res
}
