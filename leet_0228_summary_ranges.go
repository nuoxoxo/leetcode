func summaryRanges(nums []int) []string {
    len := len(nums)
	i := 0
	var E []string

	for i < len {
		foo := false
		j := i

		for j < len-1 && nums[j] == nums[j+1]-1 {
			if !foo {
				foo = true
			}
			j++
		}

		if !foo {
			E = append(E, strconv.Itoa(nums[j]))
		} else {
			E = append(E, strconv.Itoa(nums[i])+"->"+strconv.Itoa(nums[j]))
		}

		i = j + 1
	}

	return E
}
