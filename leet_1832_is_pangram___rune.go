func checkIfPangram(sentence string) bool {

    set := make(map [rune] bool)

    for _, s := range sentence {
        set[s] = true
    }

    if (len(set)) != 26 {
        return false
    }
    return true
}
