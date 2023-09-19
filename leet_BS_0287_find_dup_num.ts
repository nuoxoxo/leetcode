function findDuplicate(n: number[]): number {
    let len:number = n.length
    if (len == 2)
        return n[0]
    n.sort((a, b) => a - b)
    let mid = Math.floor(len / 2)
    let [i, j] = [1, len - 2]
    while (i ^ j && i < mid && j > mid) {
        if (n[i - 1] == n[i])
            return n[i]
        if (n[j] == n[j + 1])
            return n[j]
        ++i
        --j
    }
    return n[mid]
};
