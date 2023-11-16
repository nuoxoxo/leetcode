function findDifferentBinaryString(nums: string[]): string {
    let res:string = ''
    let i = -1
    while (++i < nums.length) {
        nums[i][i] == '0' ? res += '1' : res += '0'
    }
    return res
};
