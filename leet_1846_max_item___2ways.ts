function maximumElementAfterDecrementingAndRearranging(arr: number[]): number {
    // way 1 - simple way
    /*
    arr.sort((a, b) => a - b)
    let res = 0
    for (let n of arr) {
        res = Math.min(res + 1, n)
    }
    return res
    */
    // way 2 - greedy
    let len = arr.length
    if (len == 1)
        return len
    arr.sort((a,b)=>a-b)
    arr[0] = 1
    let res = 0
    let i = 0
    while (++i < arr.length) {
        if (arr[i] > arr[i - 1])
            arr[i] = arr[i - 1] + 1
        if (arr[i] > res)
            res = arr[i]
    }
    return res
};
