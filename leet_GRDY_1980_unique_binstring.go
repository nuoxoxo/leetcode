func findDifferentBinaryString(nums []string) string {
    res := ""
    i := 0
    for i < len(nums) {
        if nums[i][i] == '1' {
            res += "0"
        } else {
            res += "1"
        }
        i++
    }
    return res
}
