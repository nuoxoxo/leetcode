func minFallingPathSum(grid [][]int) int {
    Solutions := []func([][]int)int{
        // nCubed,
        Tracking_min_and_2nd_min,
    }
    return Solutions[0](grid)
}

func Tracking_min_and_2nd_min(G[][]int)int{

    INF := int64(math.MaxInt32)
    N := len(G)
    R, C := N, N
    var r, c int
    dp := make([][]int64, R)
    for i := range dp {
        dp[i] = make([]int64, C)
    }
    c = 0
    for c < C {
        dp[0][c] = int64(G[0][c])
        c++
    }
    r = 1
    for r < R {
        min_val, second_min_val := INF, INF
        min_idx := -1
        c = 0
        for c < C {
            if dp[r - 1][c] < min_val {
                // branched out (1) - upd. min val if a smaller one is found
                second_min_val = min_val
                min_val = dp[r - 1][c]
                min_idx = c
            } else if dp[r - 1][c] < second_min_val {
                // branched out (2) - when `min_val < PreviousRow[c] < second_min_val`
                second_min_val = dp[r - 1][c]
            }
            c++
        }
        c = 0
        for c < C {
            if c != min_idx {
                dp[r][c] = int64(G[r][c]) + min_val
            } else {
                dp[r][c] = int64(G[r][c]) + second_min_val
            }
            c++
        } 
        r++
    }
    res := INF
    for _, val := range dp[N - 1] {
        if res > val {
            res = val
        }
    }
    return int (res)
}

func nCubed(G[][]int)int{

    INF := int64(math.MaxInt32)
    N := len(G)
    R, C := N, N
    var r, c int
    dp := make([][]int64, R)
    for i := range dp {
        dp[i] = make([]int64, C)
    }
    c = 0
    for c < C {
        dp[0][c] = int64(G[0][c])
        c++
    }
    r = 1
    for r < R {
        c = 0
        for c < C {
            dp[r][c] = INF
            idx := 0
            for idx < C {
                if idx == c {
                    idx++
                    continue
                }
                temp := dp[r - 1][idx] + int64(G[r][c])
                if dp[r][c] > temp {
                    dp[r][c] = temp
                }
                idx++
            }
            c++
        }
        r++
        
    }
    res := INF
    for _, val := range dp[N - 1] {
        if res > val {
            res = val
        }
    }
    return int (res)
}
