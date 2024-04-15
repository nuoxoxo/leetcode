function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let res: number[] = []
    let i = -1
    while (++i < arr.length) {
        if ( fn(arr[i], i) ) {
            res.push(arr[i])
        }
    }
    return res
};
