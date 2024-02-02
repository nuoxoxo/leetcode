func generatePossibleNextMoves(currentState string) []string {
    size := len(currentState)
    i := 0
    res := []string{}
    for i < size - 1 {
        if currentState[i:i + 2] == "++" {
            temp := currentState[:i] + "--" + currentState[i + 2:]
            res = append(res, temp)
        }
        i++
    }
    return res
}
