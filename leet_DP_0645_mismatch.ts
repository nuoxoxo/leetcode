function findErrorNums(nums: number[]): number[] {
    const Solutions: ( (nums: number[]) => number[] )[] = [
        Solution_1pass,
        Solution_DP,
    ]
    return Solutions[
        Math.floor(Math.random()) * Solutions.length
    ]( nums )
};

const Solution_1pass = (nums:number[]): number[] => {
// 
    console.log('/Solution_1pass')
    nums.sort((a,b)=>a-b)
    let res: (number|undefined)[] = [undefined, undefined]
    // different from py code : pre-decide res[1] here 
    res[1] = nums.length == nums[nums.length - 1]? 1: nums.length
    let i = 0
    while (++i < nums.length) {
        if (nums[i] == nums[i - 1]) {
            res[0] = nums[i]
        } else if (nums[i] > nums[i - 1] + 1) {
            res[1] = nums[i - 1] + 1
        }
    }
    return res
}

const Solution_DP = (nums:number[]): number[] => {

    console.log('/Solution_DP')
    let DP: number[] = Array(nums.length).fill(0)
    let res: (number|undefined)[] = [ undefined, undefined ]
    let i = -1
    while (++i < nums.length) {
        DP[ nums[i] - 1 ] += 1
    }
    i = -1
    while (++i < nums.length) {
        if (DP[i] == 2) {
            res[0] = i + 1
        } else if (DP[i] == 0) {
            res[1] = i + 1
        }
    }
    return res
}
