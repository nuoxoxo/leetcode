func minExtraChar(s string, dictionary []string) int {
    // ["leet","code","leetcode"]
    // leetscode
    // ^^^^      i: 0 - len: 4
    //      ^^^^ i: 5 - len: 4

    // eg.2
    // ["hello","world"]
    // sayhelloworld
    //    ^^^^^      i: 3 - len: 5
    //         ^^^^^ i: 8 - len: 5

    D := make(map[int][]int)
    N := len(s)
    for begin := range s {
        for _, word := range dictionary {
            size := len(word)
            if begin + size <= N && s[begin : begin + size] == word {
                D[begin] = append(D[begin], size)
            }
        }
    }
    // fmt.Println(D)
    cost := make([]int, N + 1)
    for begin := 0; begin < N + 1; begin++ {
        cost[begin] = math.MaxInt32
    }
    cost[0] = 0
    for begin := range s {
        if cost[begin + 1] > cost[begin] + 1 {
            cost[begin + 1] = cost[begin] + 1
        }
        for _, size := range D[begin] {
            if cost[begin + size] > cost[begin] {
                cost[begin + size] = cost[begin]
            }
        }
    }
    return cost[N]
}
