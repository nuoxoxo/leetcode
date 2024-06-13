func relativeSortArray(arr1 []int, arr2 []int) []int {

    solutions := []func([]int, []int)[]int{
        // Frequency_map,
        Index_map_inplace_sort,
    }
    return solutions[0](arr1, arr2)
}

func Index_map_inplace_sort(arr1 []int, arr2 []int) []int {

    D := make(map[int]int)
    for i, n := range arr2 {
        D[n] = i
    }
    sort.SliceStable(arr1, func(l, r int) bool {
        // note that l, r are indexes, not val
        L, lok := D[arr1[l]]
        R, rok := D[arr1[r]]
        if lok && rok {
            return L < R
        } else if lok {
            return true
        } else if rok {
            return false
        }
        return arr1[l] < arr1[r]
    })
    return arr1
}

func Frequency_map(arr1 []int, arr2 []int) []int {

    var contains func([]int, int) bool
    contains = func(arr []int, num int) bool {
        for _, n := range arr {
            if num == n {
                return true
            }
        }
        return false
    }

    R := []int{}
    D := make(map[int]int)
    for _, n := range arr1 {
        // 1. - elements that arr2 does not have
        if !contains(arr2, n) {
            R = append(R, n)
        } else {
            // 2. - get freq of elems that arr1 does have
            D[n]++
        }
    }
    L := []int{}
    sort.Ints(R)
    for _, n := range arr2 {
        if freq, OK := D[n]; OK {
            temp := make([]int, freq)
            i := 0
            for i < freq {
                temp[i] = n
                i++
            }
            L = append(L, temp ...)
        }
    }
    return append(L, R ...)
}

