func compareVersion(version1 string, version2 string) int {

    Solutions := []func(string, string)int{
        Extra_space,
        Linear_time,
    }
    return Solutions[0](version1, version2)
}

func Linear_time(version1 string, version2 string) int {

    size1 := len(version1)
    size2 := len(version2)
    l := 0
    r := 0
    for l < size1 || r < size2 {
        L := 0
        ll := l
        for ll < size1 && version1[ll] != '.' {
            L = L * 10 + int(version1[ll] - '0')
            ll++
        }
        R := 0
        rr := r
        for rr < size2 && version2[rr] != '.' {
            R = R * 10 + int(version2[rr] - '0')
            rr++
        }
        if L < R {
            return -1
        }
        if L > R {
            return 1
        }
        l = ll + 1
        r = rr + 1
    }
    return 0
}

func Extra_space(version1 string, version2 string) int {

    var splitline func(string)[]int
    splitline = func(s string)[]int{
        res := make([]int, 0)
        tmp := strings.Split(s, ".")
        for _, w := range tmp {
            n, _ := strconv.Atoi(w)
            res = append(res, n)
        }
        return res
    }

    L := splitline(version1)
    R := splitline(version2)
    for len(L) < len(R) {
        L = append(L, 0)
    }
    for len(L) > len(R) {
        R = append(R, 0)
    }
    N := len(L)
    i := 0
    for i < N {
        if L[i] < R[i] {
            return -1
        }
        if L[i] > R[i] {
            return 1
        }
        i++
    }
    return 0
}

