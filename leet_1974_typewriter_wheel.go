func minTimeToType(word string) int {
    res := len(word)
    for i, char := range word {
        var dist int
        if i == 0 {
            dist = int(char) - int('a')
        } else {
            dist = int(char) - int(word[i - 1])
        }
        if dist < 0 {
            dist = -dist
        }
        res += min(26 - dist, dist)
    }
    return res
}
