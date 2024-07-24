func sortJumbled(mapping []int, nums []int) []int {

    solutions := []func([]int, []int) []int {
        // Valid_soln,
        Why_is_it_wrong___now_its_correct,
        /// why is it wrong?
        ///     ---> because `l, r` in `func(l, r int)bool` are indices
        ///     of a temp state when the sort is happening,
        ///     not the original indices in nums 
    }
    return solutions[0](mapping, nums)
}

func Valid_soln(mapping []int, nums []int) []int {

    caching := make(map[int]int)
    var f func(int) int = func(n int) int {
        if n == 0 {
            return mapping[0]
        }
        if res, ok := caching[n]; ok {
            return res
        }
        tt := 0
        mult := 1
        for n > 0 {
            tt += mapping[ n % 10 ] * mult
            n /= 10
            mult *= 10
        }
        caching[n] = tt
        return tt
    }

    tuples := make(map[int][2]int)
    for index, n := range nums {
        tuples[n] = [2]int{ f(n), index }
    }

    sort.Slice(nums, func(l, r int)bool{
        L, R := tuples[nums[l]], tuples[nums[r]]
        if L[0] == R[0]  {
            return L[1] < R[1]
        }
        return L[0] < R[0]
    })
    return nums
}

func Why_is_it_wrong___now_its_correct(mapping []int, nums []int) []int {

    caching := make(map[int]int)

    var f func(int)int = func(n int) int {
        if n == 0 {
            return mapping[0]
        }
        if res, ok := caching[n]; ok {
            return res
        }
        res := 0
        mult := 1
        for n > 0 {
            res += mapping[ n % 10 ] * mult
            n /= 10
            mult *= 10
        }
        caching[n] = res
        return res
    }

    sort.Slice(nums, func(l, r int)bool{
        L, R := f(nums[l]), f(nums[r])
        if L == R {
            return l < r
        }
        return L < R
    })
    return nums
}

// passed all but one really big input
/*
[9,8,7,6,5,4,3,2,1,0]
[0,1,2,3,4,5,6,7,8,9]
[5,6,7,8,9,4,3,2,1,0]
[9,999,9999,9,999999,999]
[9,0,8,1,2,3,4,5,6,7]
[876543210, 234567890, 97654321]
 [9,8,7,6,5,4,3,2,1,0]
[987654321, 123456789, 456789123, 789456123, 321654987]
[7,8,9,0,1,2,3,4,5,6]
[987654321, 876543210, 765432109, 654321098, 543210987, 432109876, 321098765, 210987654, 109876543, 987654321]
[5,4,3,2,1,0,9,8,7,6]
[  999999998, 888888887, 777777776, 666666665, 555555554,   444444443, 333333332, 222222221, 111111110, 999999997,   888888886, 777777775, 666666664, 555555553, 444444442,   333333331, 222222220, 111111109, 999999996, 888888885,   777777774, 666666663, 555555552, 444444441, 333333330,   222222219, 111111108, 999999995, 888888884, 777777773,   666666662, 555555551, 444444440, 333333329, 222222218,   111111107, 999999994, 888888883, 777777772, 666666661,   555555550, 444444439, 333333328, 222222217, 111111106]
[9,8,7,6,5,4,3,2,1,0]
[0,1,2,3,4,5,6,7,8,9]
[9, 0, 1, 8, 2, 7, 6, 3, 4, 5]
[  987, 654, 321, 978, 543, 210, 876, 543, 210, 987,  654, 321, 978, 543, 210, 876, 543, 210, 987, 654,  321, 978, 543, 210, 876, 543, 210, 987, 654, 321,  978, 543, 210, 876, 543, 210, 987, 654, 321, 978,  543, 210, 876, 543, 210, 987, 654, 321, 978, 543,  210, 876, 543, 210, 987, 654, 321, 978, 543, 210,  876, 543, 210, 987, 654, 321, 978, 543, 210, 876,  543, 210, 987, 654, 321, 978, 543, 210, 876, 543,  210, 987, 654, 321, 978, 543, 210, 876, 543, 210,  987, 654, 321, 978, 543, 210, 876, 543, 210, 987]
*/

