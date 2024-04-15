declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    if (colsCount * rowsCount ^ this.length) {
        return []
    }
    let res: number[][] = new Array(rowsCount).fill([]).map(() => [])
    let r: number = -1, c: number
    while (++r < this.length) {
        c = Math.floor(r / rowsCount)
        if (c % 2) {
            res[rowsCount - 1 - r % rowsCount][c] = this[r]
        } else {
            res[r % rowsCount][c] = this[r]
        }
    }
    return res
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
