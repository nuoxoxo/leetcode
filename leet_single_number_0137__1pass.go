import (
	"fmt"
	"sort"
)

func singleNumber(nums []int) int {
	len := len(nums)
	if len == 1 {
		return nums[0]
	}
	sort.Ints(nums)
	if nums[0] != nums[1] {
		return nums[0]
	}
	var i int
	for i = 0; i < len - 2; i++ {
		if nums[i] != nums[i + 1] && nums[i + 1] != nums[i + 2] {
			break
		}
	}
	return nums[i + 1]
}
