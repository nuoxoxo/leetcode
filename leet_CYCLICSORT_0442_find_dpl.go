func findDuplicates(nums []int) []int {

    Solutions := []func([]int)[]int {
        Cyclic_sort,
        // Cyclic_sort_different_loop,
        // Using_extra_space,
    }
    return Solutions[0](nums)
}

func Cyclic_sort_different_loop(nums []int) []int {
    res := []int{}
    N := len(nums)
    i := 0
    for i < N {
        if nums[i] != i + 1 && nums[i] != nums[nums[i] - 1] {
            nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        } else {
            i++
        }
        // Cyclic sort - idea :
        //      swap the current number to its correct index
        //      until it's in the right place
    }
    i = 0
    fmt.Println(nums)
    for i < N {
        if nums[i] != i + 1 {
            res = append(res, nums[i])
        }
        i++
    }
    return res
}

func Cyclic_sort(nums []int) []int {
    res := []int{}
    N := len(nums)
    i := 0
    for i < N {
        for nums[i] != i + 1 && nums[i] != nums[nums[i] - 1] {
            nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        }
        // Cyclic sort - idea :
        //      swap the current number to its correct index
        //      until it's in the right place
        i++
    }
    i = 0
    fmt.Println(nums)
    for i < N {
        if nums[i] != i + 1 {
            res = append(res, nums[i])
        }
        i++
    }
    return res
}

func Using_extra_space(nums []int) []int {
    N := len(nums)
    res := []int{}
    D := make([]int, N)
    for _, n := range nums {
        if D[n - 1] == 1 {
            res = append(res, n)
        } else {
            D[n - 1]++
        }
    }
    return res
}
