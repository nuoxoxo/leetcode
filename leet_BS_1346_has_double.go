func checkIfExist(arr []int) bool {

    Solutions := []func([]int)bool{
        Solution_mult_2_array,
        // Solution_binary_search,
        // Solution_even_odd,
    }
    return Solutions[ rand.Intn(len(Solutions)) ](arr)
}

func Solution_mult_2_array(arr []int) bool {
    zeroes := 0
    for _, n := range arr {
        if n == 0 {
            zeroes++
        }
    }
    if zeroes > 1 {
        return true
    }
    check := []int{}//make([]int, N)
    for _, n := range arr {
        if n != 0 {
            check = append(check, 2 * n)
        }
    }
    for _, num := range check {
        for _, n := range arr {
            if n == num {
                return true
            }
        }
    }
    return false
}

func Solution_binary_search(arr []int) bool {
    sort.Ints(arr)
    for idx, n := range arr {
        l, r := 0, len(arr) - 1
        tar := n * 2
        for l <= r {
            mid := (r - l) / 2 + l
            if arr[mid] == tar && mid != idx {
                return true
            } else if arr[mid] < tar {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
    return false
}
