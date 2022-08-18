func minSetSize(arr []int) int {
    mp := make(map[int]int)
    a2 := [] int {}
    for _, n := range arr {
        mp[n]++
    }
    for _, n := range mp {
        a2 = append(a2, n)
    }
    sort.Slice(a2, func(i, j int) bool {
        return a2[i] > a2[j]
    })
    // fmt.Println(a2)
    la := len(arr)
    count := la
    res := 0
    for _, n := range a2 {
        if count <= la / 2 {
            break
        }
        count -= n
        res++
    }
    return res
}
