func mySqrt(x int) int {
    Solutions := []func (int) int {
        Solution_Binary_Search,
        Solution_Newton,
        Solution_Bruteforce,
    }
    return Solutions[rand.Intn(len(Solutions))]( x )
}

func Solution_Binary_Search(x int) int {
    fmt.Println("/Solution_Binary_Search")
    res, L, R := 0, 0, x
    for L <= R {
        mid := (R - L) / 2 + L
        sq := mid * mid
        if sq == x {
            return mid
        }
        if sq > x {
            R = mid - 1
        } else {
            res = mid
            L = mid + 1
        }
    }
    return res
}

func Solution_Newton(x int) int {
    fmt.Println("/Solution_Newton")
    if x == 0 || x == 1 {
        return x
    }
    res := x
    for res * res > x {
        res = (res + x / res) / 2
    }
    return res
}

func Solution_Bruteforce(x int)int{
    fmt.Println("/Solution_Bruteforce")
    if x == 0 || x == 1 {
        return x
    }
    res := 1
    for res * res <= x && (res+1) * (res+1) <= x {
        res += 1
    }
    return res
}

