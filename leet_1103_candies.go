func distributeCandies(candies int, num_people int) []int {
    res := make([]int, num_people)
    idx := 0
    c := 1
    var n int
    for candies > 0 {
        if candies < c {
            n = candies
        } else {
            n = c
        }
        candies -= n
        res[idx] += n
        idx = (idx + 1) % num_people
        c++
    }
    return res
}
