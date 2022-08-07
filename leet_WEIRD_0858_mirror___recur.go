func mirrorReflection(p int, q int) int {
    if p % 2 == 0 && q % 2 == 0 {
            return mirrorReflection(p / 2, q / 2)
    }
    return 1 + q % 2 - p % 2
}
