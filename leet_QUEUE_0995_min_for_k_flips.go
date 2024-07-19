func minKBitFlips(nums []int, k int) int {

    // [1,1,0], k = 2
    //   -> [1,0,1] -> we can flip these 2
    //         ^ ^ 
    //   -> [0,0,1] -> or we can flip these
    //       ^ ^ 
    //   -> impossible bc. a 0- or 1-bit is left either way
    //
    // [0,0,0,1,0,1,1,0], k = 3
    //   -> [1,1,1,1,0,1,1,0] -> step1
    //       ^ ^ ^ 
    //   -> [1,1,1,1,1,0,0,0] -> step2
    //               ^ ^ ^
    //   then flip the final len-3 subarr
    //
    //       Strategy
    // once we can flip we flip, store the window flipped, swicth state and gain 1
    // once we meet the R-index of a window, dispose this window, swich the state
    //
    //       Tool
    // a queue to store the window where flips happen.
    // a window is identified by the R-index of the window.

    res := 0
    flipping := 0
    deque := []int{}
    for i, curr := range nums {
        if len(deque) > 0 && deque[0] == i {
            // seen it befoe
            deque = deque[1:]
            flipping ^= 1
        }
        if flipping == curr {
            // flip once its possible to flip
            deque = append(deque, i + k)
            flipping ^= 1
            res += 1
        }
    }
    if len(deque) > 1 {
        return -1
    }
    if len(deque) == 0 || deque[0] == len(nums) {
        return res
    }
    return -1
}
