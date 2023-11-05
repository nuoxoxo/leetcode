function getWinner(arr: number[], k: number): number {
    let hi:number = Math.max(...arr)
    let len:number = arr.length
    if (len <= k)
        return hi
    let count:number = 0
    let i = 0
    let res: number = arr[0]
    while (++i < len) {
        if (res < arr[i]) {
            count = 1
            res = arr[i]
        } else {
            count++
        }
        if (count == k)
            return res
    }
    // console.log(hi)
    return hi
};
