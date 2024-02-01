func lemonadeChange(bills []int) bool {
    five := 0
    ten := 0
    // no need to track $20 coz each client pays with either a $5, $10, or $20
    for _, b := range bills {
        if b == 5 {
            five++
        } else if b == 10 && five > 0 {
            ten++
            five--
        } else if b == 20 && five > 0 && ten > 0 {
            ten--
            five--
        } else if b == 20 && five > 2 {
            five -= 3
        } else {
            return false
        }
    }
    return true
}
