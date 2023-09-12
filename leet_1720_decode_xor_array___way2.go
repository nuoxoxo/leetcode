func decode(encoded []int, first int) []int {
    res := []int{first}
    i := 0
    for i < len(encoded) {
        res = append(res, encoded[i] ^ res[len(res)-1])
        i++
    }
    return res
}
