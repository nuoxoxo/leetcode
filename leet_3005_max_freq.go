func maxFrequencyElements(nums []int) int {
    Solutions := []func([]int)int{
        // Space_heavy,
        Best_solution,
    }
    return Solutions[ 0 ](nums)
}

func Best_solution(nums []int) int {
    D := map[int]int{}
    top, times := -1, 0
    for _, n := range nums {
        D[n]++
        if D[n] > top {
            top = D[n]
            times = 0
        }
        if D[n] == top {
            times ++
        }
    }
    return top * times
}

func Space_heavy(nums []int) int {

    D := map[int]int{}
    for _, n := range nums {
        D[n]++
    }
    N := len(D)
    A := make([]int, N)
    i := 0
    for _, v := range D {
        A[i] = v
        i++
    }
    sort.SliceStable(A, func (l, r int) bool {
        return l < r
    })
    top, res := A[0], 0
    for _, v := range A {
        if v == top {
            res += v
        } else {
            break
        }
    }
    return res
}

