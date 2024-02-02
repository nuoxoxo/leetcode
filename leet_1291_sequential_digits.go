func sequentialDigits(low int, high int) []int {
    Solutions := []func(int, int)[]int{
        Enumeration,
        // Bruteforce_TLE,
    }
    return Solutions[ rand.Intn(len(Solutions)) ]( low, high )
}

func Enumeration(low int, high int) []int {
    res := []int{}
    n := 2
    for n < 11 {
        i := 1
        for i < 11 - n {
            num := 0
            j := 0
            for j < n {
                num = num * 10 + i + j
                j++
            }
            if num >= low && num <= high {
                res = append(res, num)
            }
            i++
        }
        n++
    }
    return res
}

func Bruteforce_TLE(low int, high int) []int {

    isSD := func(num int) bool {
        s := strconv.Itoa(num)
        for i := 0; i < len(s) - 1; i++ {
            if int(s[i + 1] - '0') - int(s[i] - '0') != 1 {
                return false
            }
        }
        return true
    }
    res := []int{}
    for n := low; n <= high; n++ {
        if isSD(n) {
            res = append(res, n)
        }
    }
    return res
}

