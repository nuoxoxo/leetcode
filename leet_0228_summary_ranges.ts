function summaryRanges(nums: number[]): string[] {
    let len:number = nums.length
    let i:number = 0
    let E:string[] = []
    while (i < len) {
        let foo:boolean = false
        let j:number = i
        while (j < len - 1 && nums[j] === nums[j + 1] - 1){
            if (!foo) {
                foo = true
            }
            j++
        }
        if (!foo) {
            E.push(nums[j].toString())
        } else {
            E.push(nums[i].toString() + "->" + nums[j].toString())
        }
        i = j + 1
    }
    return E
};
