func minSetSize(arr []int) int {
    mp := make(map [int] int)
    a2 := [] int {}
    for _, n := range arr {
        mp[n]++
    }
    // fmt.Println(mp)
    for _, n := range mp {
        a2 = append(a2, n)
    }
    // fmt.Println(a2)
    sort.Sort(sort.Reverse(sort.IntSlice(a2)))
    // fmt.Println(a2)
    la := len(arr)
    count := la
    res := 0
    for _, n := range a2 {
        if count <= la / 2 {
            return res
        }
        count -= n
        res++
    }
    return res
}
