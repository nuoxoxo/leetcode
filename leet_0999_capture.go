func numRookCaptures(board [][]byte) int {
    res := 0
    R := len(board)
    C := len(board[0])
    var r, c, i int
    found := false

    r = -1
    for r = 0; r < R; r++ {
        for c = 0; c < C; c++ {
            if board[r][c] == 'R' {
                found = true
                break
            }
        }
        if found {
            break
        }
    }

    // L R
    i = r
    for i = i - 1; i > -1; i-- {
        if board[i][c] == 'B' {
            break
        }
        if board[i][c] == 'p' {
            res++
            break
        }
    }
    i = r
    for i = i + 1; i < R; i++ {
        if board[i][c] == 'B' {
            break
        }
        if board[i][c] == 'p' {
            res++
            break
        }
    }

    // U D
    i = c
    for i = i - 1; i > -1; i-- {
        if board[r][i] == 'B' {
            break
        }
        if board[r][i] == 'p' {
            res++
            break
        }
    }
    i = c
    for i = i + 1; i < C; i++ {
        if board[r][i] == 'B' {
            break
        }
        if board[r][i] == 'p' {
            res++
            break
        }
    }
    return res
}
