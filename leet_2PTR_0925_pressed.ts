function isLongPressedName(name: string, typed: string): boolean {
    let n = 0
    let t = -1
    while (++t < typed.length) {
        if (n < name.length && name[n] == typed[t]) {
            ++n
        } else if (t == 0 || typed[t] != typed[t - 1]) {
            return false
        }
    }
    return n === name.length
};
