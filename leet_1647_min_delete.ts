function minDeletions(s: string): number {
    let count:number[] = Array(26).fill(0)
    for (let c of s) {
        count[ c.charCodeAt(0) - 'a'.charCodeAt(0) ]++
    }
    console.log(count)
    count.sort((a, b) => a - b)
    console.log(count)
    let i = -1
    let res:number = 0
    while (++i < 25) {
        if (!count[i] || count[i] != count[i + 1]) {
            continue
        }
        count[i]--
        res++
        i = -1
    }
    return res
};
