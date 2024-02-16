type KV struct {
    key int
    val int
}

func findLeastNumOfUniqueInts(arr []int, k int) int {
    Solutions := []func([]int, int) int {
        Sorting_by_occurences_Not_greedy,
    }
    return Solutions[ 0 ]( arr, k )
}

func Sorting_by_occurences_Not_greedy(arr []int, k int) int {
    dict := map[int]int{}
    for _, n := range arr {
        dict[n]++
    }
    sorted_dict := [] KV {}
    for k, v := range dict {
        sorted_dict = append( sorted_dict, KV{ key:k, val:v } )
    }
    sort.Slice(sorted_dict, func(l, r int) bool {
        return sorted_dict[ l ].val > sorted_dict[ r ].val
    })
    A := []int{}
    for _, kv := range sorted_dict {
        i := 0
        for i < kv.val {
            A = append(A, kv.key)
            i++
        }
    }
    // fmt.Println(A)
    for k > 0 {
        A = A[:len(A) - 1]
        k--
    }
    counter := make( map[int]int )    
    for _, n := range A {
        counter[n]++
    }
    // fmt.Println(counter)
    return len(counter)
}
