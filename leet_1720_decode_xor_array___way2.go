func decode(encoded []int, first int) []int {
    res := []int{first}
    for i := 0; i < len(encoded); i++ {
        res = append(res, encoded[i] ^ res[len(res)-1])
    }
    return res
}
