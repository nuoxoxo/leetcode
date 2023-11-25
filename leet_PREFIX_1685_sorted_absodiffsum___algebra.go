func getSumAbsoluteDifferences(nums []int) []int {

    len = len(nums)
    L := 0
    R := 0
    var res []int
    for _, n := range nums {
        R += n
    }
    for i, n := range nums {
        L += n
        res = append(res, n * (2 * i + 1 - len) - L + R)
        R -= n
    }
    return res
}
