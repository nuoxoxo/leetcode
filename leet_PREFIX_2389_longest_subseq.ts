function answerQueries(nums: number[], queries: number[]): number[] {
    let n:number = nums.length
    let m:number = queries.length
    let prefix:number = 0
    let i:number, j:number

    let res:number[] = new Array(m).fill(NaN)
    console.log(m, res)
    let p:number[] = []

    nums.sort((a, b) => {return a - b})
    // console.log(nums)
    i = -1
    while (++i < n) {
        prefix += nums[i]
        p.push(prefix)
    }
    i = -1
    while (++i < m) {
        let tmp:number = 0
        j = -1
        while (++j < n) {
            if (p[j] > queries[i]) {
                break
            }
            ++tmp
        }
        res[i] = tmp
    }
    return res
};
