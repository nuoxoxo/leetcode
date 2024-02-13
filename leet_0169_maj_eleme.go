func majorityElement(nums []int) int {
    init := false
    var res int
    cnt := 1
    for _, n := range nums {
        if ! init {
            init = true
            res = n
        } else {
            if res == n {
                cnt++
            } else {
                cnt--
                if cnt == 0 {
                    res = n
                    cnt = 1
                }
            }
        }
    }
    return res
}
