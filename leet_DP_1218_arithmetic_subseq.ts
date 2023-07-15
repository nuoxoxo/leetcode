function longestSubsequence(arr: number[], diff: number): number {
    let M: Object = new Object()
    for (let n of arr)
        M[n] = (M[n - diff] || 0) + 1
        // M[n] = M[n - diff] + 1 // wrong
    return Math.max(...Object.values(M))
};
