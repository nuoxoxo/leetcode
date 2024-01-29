func findContentChildren(g []int, s []int) int {
    Solutions := []func( []int, []int ) int {
        Solution_2_pointers,
    }
    return Solutions[ rand.Intn( len(Solutions))] (g, s)
}

func Solution_2_pointers(g []int, s []int) int {

    fmt.Println("/Solution_2_pointers")
    sort.Ints(g)
    sort.Ints(s)
    L, R := 0, 0
    for L < len(g) && R < len(s) {
        if g[L] <= s[R] {
            L++
        }
        R++
    }
    return L
}
