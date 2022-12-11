package main
   
import (
    "fmt"
    "sort"
)

func arrayPairSum(nums []int) int {
    sort.Ints (nums)
    res := 0
    min := 0
    i := 0
    for i < len(nums) {
        if nums[i] < nums[i + 1] {
            min = nums[i]
        } else {
            min = nums[i + 1]
        }
        res += min
        i += 2
    }
    return res
}
