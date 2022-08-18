func minSetSize(arr []int) int {
    mp := make(map[int]int)
    a2 := [] int {}
    for _, n := range arr {
        mp[n]++
    }
    for _, n := range mp {
        a2 = append(a2, n)
    }
    sort.Ints(a2)
    // fmt.Println(a2)
    la := len(arr)
    count := la
    res := 0
    for i := len(a2) - 1; i > -1; i-- {
        if count <= la / 2 {
            break
        }
        count -= a2[i]
        res++
    }
    return res
}
