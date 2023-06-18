function numRookCaptures(board: string[][]): number {
    let res:number = 0
    let R:number = board.length
    let C:number = board[0].length
    let r:number, c:number, i:number
    let found:boolean = false
    r = -1
    while (++r < R) {
        c = -1
        while (++c < C)
        {
            if (board[r][c] == 'R')
            {
                found = true 
                break
            }
        }
        if (found)
            break
    }

    // L R
    i = r
    while (--i > -1)
    {
        if (board[i][c] == 'B')
            break
        if (board[i][c] == 'p')
        {
            ++res
            break
        }
    }
    i = r
    while (++i < R)
    {
        if (board[i][c] == 'B')
            break
        if (board[i][c] == 'p')
        {
            ++res
            break
        }
    }

    // U D
    i = c
    while (--i > - 1)
    {
        if (board[r][i] == 'B')
            break
        if (board[r][i] == 'p')
        {
            ++res
            break
        }
    }
    i = c
    while (++i < C)
    {
        if (board[r][i] == 'B')
            break
        if (board[r][i] == 'p')
        {
            ++res
            break
        }
    }
    return res
};
