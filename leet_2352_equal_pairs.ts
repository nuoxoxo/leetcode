function equalPairs(grid: number[][]): number {
    let dict = new Object()
    let len:number = grid.length
    let cols = new Array(len).fill('')
    let res:number = 0 
    for (let nums of grid) {
        let s:string = ''
        let i:number = -1
        while (++i < len) {
            let n:string = nums[i].toString()
            s += ' ' + n
            cols[i] += ' ' + n
        }
        if (dict.hasOwnProperty(s)) {
            dict[s] += 1
        } else {
            dict[s] = 1
        }
        // console.log(s, dict[s])
    }
    for (let c of cols) {
        dict.hasOwnProperty(c) ? res += dict[c] : null;
    }
    // console.log(dict)
    return res
};
