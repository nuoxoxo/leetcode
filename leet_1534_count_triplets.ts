function countGoodTriplets(arr: number[], a: number, b: number, c: number): number {
    let res = 0
    let L = arr.length
    let i = -1;
    while (++i < L - 2) {
        let j = i
        while (++j < L - 1) {
            let k = j
            while (++k < L) {
                if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[k] - arr[i]) <= c) {
                    res += 1
                }
            }
        }
    }
    return res
};
