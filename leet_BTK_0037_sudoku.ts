/**
 Do not return anything, modify board in-place instead.
 */
function solveSudoku(board: string[][]): void {
    let [r, c] = next_move(board)
    if (r < 0) {
        return
    }
    let guess = 0
    while (++guess < 10) {
        if (is_legal(board, guess, r, c)) {
            board[r][c] = guess.toString()
            solveSudoku(board)
            if (next_move(board)[0] == -1) {
                return
            }
            board[r][c] = '.'
        }
    }
};

function next_move(G: string [][]): number[] {
    let r = -1
    while (++r < 9) {
        let c = -1
        while (++c < 9) {
            if (G[r][c] == '.') {
                return [r, c]
            }
        }
    }
    return [-1, -1]
}

function is_legal(G: string[][], guess: number, r: number, c: number): boolean {
    if (G[r].includes(guess.toString())) {
        return false
    }
    let tmp = []
    for (let row of G) {
        tmp.push(row[c])
    }
    if (tmp.includes(guess.toString())) {
        return false
    }
    let r0 = Math.floor(r / 3) * 3
    let c0 = Math.floor(c / 3) * 3
    let rr = r0 - 1, cc
    while (++rr < r0 + 3) {
        cc = c0 - 1
        while (++cc < c0 + 3) {
            if (G[rr][cc] == guess.toString()) {
                return false
            }
        }
    }
    return true
}
