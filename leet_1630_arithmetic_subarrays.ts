function checkArithmeticSubarrays(nums: number[], l: number[], r: number[]): boolean[] {
    let res = []
    let m = l.length
    let i = -1
    while (++i < m) {
        let temp = nums.slice(l[i], r[i] + 1)
        // console.log(temp)
        if (temp.length == 2) {
            res.push(true)
            continue 
        }
        temp.sort((a, b) => a - b)
        let diff = temp[1] - temp[0]
        let j = 1
        let found = false
        while (++j < temp.length) {
            if (temp[j] - temp[j - 1] != diff) {
                found = true
                break
            }
        }
        if (!found)
            res.push(true)
        else
            res.push(false)
    }
    return res
};
