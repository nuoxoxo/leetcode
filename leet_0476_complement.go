import "strconv"

func findComplement(num int) int {
    s := strconv.FormatInt(int64(num), 2)
    r := ""
    for _, c := range s {
        if c == rune('1') {
            r += "0"
        } else {
            r += "1"
        }
    }
    if res, err := strconv.ParseInt(r, 2, 64); err != nil {
        return -1
    } else {
        return int(res)
    }
    /*
    // let s = (num >> 0).toString(2) // also works
    // let s = num.toString(2) // also works
    let s = (num >>> 0).toString(2)
    let r = ''
    for (let c of s) {
        r += (c == '0') ? '1' : '0' 
    }
    // console.log(r)
    return parseInt(r, 2);
    */
}
