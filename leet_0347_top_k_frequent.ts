function topKFrequent(nums: number[], k: number): number[] {
    let dict: object = new Object()
    for (let n of nums) {
        if (dict.hasOwnProperty(n))
            dict[n]++
        else
            dict[n] = 1
    }
    let res: number[] = []
    let arr: number[][] = []
    for (let d in dict)
        arr.push([d, dict[d]])
    arr.sort((a, b) => b[1] - a[1])
    res = []
    console.log(arr)
    while (k--)
        res.push(arr.shift()[0])
    return res
};
