func checkRecord(N int) int {

    MOD := int(1e9 + 7)
    // fmt.Println(MOD)

    has_cache := make([][][] bool, N)
    cache := make([][][]int, N)
    i := 0
    for i < N {
        has_cache[i] = make([][]bool, 2)
        cache[i] = make([][]int, 2)
        j := 0
        for j < 2 {
            has_cache[i][j] = make([]bool, 3)
            cache[i][j] = make([]int, 3)
            j++
        }
        i++
    }

    var DFS func(days, A, L int) int
    DFS = func (days, A, L int) int {

        // base and caching
        if days == N {
            return 1
        }
        if has_cache[days][A][L] {
            return cache[days][A][L]
        }

        res := 0

        // present - nothing happens
        res += DFS(days + 1, A, 0)
        res %= MOD

        // absent - add to A where max(A) == 1
        if A == 0 {
            res += DFS(days + 1, A + 1, 0)
            res %= MOD
        }

        // late - add to consecutive L where max(L) == 2
        if L < 2 {
            res += DFS(days + 1, A, L + 1)
            res %= MOD
        }
        cache[days][A][L] = res
        has_cache[days][A][L] = true
        return res
    }

    days, A, L := 0, 0, 0

    return DFS(days, A, L)
}
