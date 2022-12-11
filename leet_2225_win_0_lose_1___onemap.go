func findWinners(matches [][]int) [][]int {
    players := make(map[int] int)
    winall := make([]int, 0)
    lose1 := make([]int, 0)
    for _, m := range matches {
        players[m[0]] += 0
        players[m[1]] += 1
    }
    for key, val := range players {
        if val == 0 {
            winall = append(winall, key)
        }
        if val == 1 {
            lose1 = append(lose1, key)
        }
    }
    sort.Ints(winall)
    sort.Ints(lose1)
    return ([][]int { winall, lose1 })
}
