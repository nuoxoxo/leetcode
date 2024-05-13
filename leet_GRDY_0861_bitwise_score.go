func matrixScore(grid [][]int) int {

    solutions := []func([][]int)int{
        greedy_cols_dp,
    }
    return solutions[0](grid)
}

func greedy_cols_dp(G[][]int)int{

    //  1/2 - max the rows :
    //      the most significant has to be 1
    for r := range G {
        for G[r][0] == 0 {
            for c := range G[r] {
                G[r][c] ^= 1
            }
        }
    }

    //  2/2 - max the cols :
    //      as many 1s as possible
    cols := make([]int, C)
    for c := range cols {
        cols[c] = 0
    }
    for r := range G {
        for c := range G[r] {
            cols[c] += G[r][c]
        }
    }
    for c := range cols {
        if cols[c] < R - cols[c] {
            cols[c] = R - cols[c]
        }
    }
    res := 0
    for c := range cols {
        res = res * 2 + cols[c]
    }
    return res
}
