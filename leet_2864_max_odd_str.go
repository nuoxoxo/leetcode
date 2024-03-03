func maximumOddBinaryNumber(s string) string {
    Solutions := []func(string) string {
        string_manipulation,
        byte_array,
    }
    return Solutions[1](s)
}

func byte_array(s string)string{
    N := len(s)
    var bytes []byte = make ([]byte, N)
    bytes[N - 1] = '1'
    one := -1
    for _, c := range s {
        if c == '1' {
            one++
        }
    }
    i := 0
    for i < one {
        bytes[i] = '1'
        i++
    }
    i = one
    for i < N - 1 {
        bytes[i] = '0'
        i++
    }
    return string(bytes)
}

func string_manipulation(s string)string {
    res := ""
    one := 0
    for _, c := range s {
        if c == '1' {
            one++
        }
    }
    zero := len(s) - one
    i := 1
    for i < one {
        res += "1"
        i++
    }
    i = 0
    for i < zero {
        res += "0"
        i++
    }
    return res + "1"
}
