func countSubarrays(nums []int, minK int, maxK int) int64 {
    var res int64 = 0
    L := 0
    R := 0
    foundL := false
    foundR := false
    start := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] < minK || nums[i] > maxK {
            foundL = false
            foundR = false
            start = i + 1
        }
        if nums[i] == minK {
            foundL = true
            L = i
        }
        if nums[i] == maxK {
            foundR = true
            R = i
        }
        if foundL && foundR {
            temp := 0
            if L < R {
                temp = L
            } else {
                temp = R
            }
            res += int64(temp - start + 1)
        }
    }
    return res 
}
