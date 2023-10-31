function findArray(pref: number[]): number[] {
    let i: number = pref.length
    while (--i > 0) {
        pref[i] = pref[i] ^ pref[i - 1]
    }
    return pref
};
