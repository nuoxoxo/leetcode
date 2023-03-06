function findKthPositive(arr: number[], k: number): number {
    for (let n of arr) {
        if (n <= k)
            k++
    }
    return k
};
