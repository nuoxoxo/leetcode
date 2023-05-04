function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let i = -1;
    while (++i < arr.length) {
        arr[i] = fn(arr[i], i)
    }
    return arr
};
