func flipAndInvertImage(image [][]int) [][]int {
    res := [][]int {}
    for _, r := range image {
        tmp := []int {}
        rr := r
        for i, j := 0, len(rr) - 1; i < j; i, j = i + 1, j - 1 {
            rr[i], rr[j] = rr[j], rr[i]
        }
        for _, n := range rr {
            if n == 1 {
                tmp = append(tmp, 0)
            } else {
                tmp = append(tmp, 1)
            }
        }
        res = append(res, tmp)
    }
    return res
}
