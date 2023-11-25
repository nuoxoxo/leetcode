function largestNumber(nums: number[]): string {
    let S: string[] = nums.map(n => n.toString())   
    S.sort((a, b) => (b + a).localeCompare(a + b))
    let res: string = '';
    for (let s of S)
        res += s
    let i = 0
    while (i < res.length && res[i] === '0')
        ++i
    if (i === res.length)
        return '0'
    return res;
};
