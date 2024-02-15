func largestPerimeter(nums []int) int64 {

    Solutions := []func([]int)int64{
        Solution_sorting_and_greedy,
    }
    return Solutions[ 0 ]( nums )
}

func Solution_sorting_and_greedy(nums[]int)int64 {
    sort.Ints( nums )
    var curr, res int64 = int64(nums[0]), -1
    i := 1
    for i < len(nums) {
        if int64(nums[i]) < curr {
            res = curr + int64(nums[i])
        }
        curr = curr + int64(nums[i])
        i++
    }
    return res
}
