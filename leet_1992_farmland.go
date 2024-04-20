func findFarmland(land [][]int) [][]int {
    R, C := len(land), len(land[0])
    Seen := make(map [[2]int] bool)
    res := [][]int{}
    r := 0
    for r < R {
        c := 0
        for c < C {
            if land[r][c] == 1 && ! Seen[[2]int{r, c}] {
                er, ec := r, c
                for er + 1 < R && land[er + 1][ec] == 1 {
                    er++
                }
                for ec + 1 < C && land[er][ec + 1] == 1 {
                    ec++
                }
                res = append(res, []int{r, c, er, ec})
                i := r
                for i < er + 1 {
                    j := c
                    for j < ec + 1 {
                        node := [2]int{i, j}
                        Seen[node] = true
                        j++
                    }
                    i++
                }
            }
            c++
        }
        r++
    }
    return res
}
