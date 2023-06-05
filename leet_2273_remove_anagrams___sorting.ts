function removeAnagrams(words: string[]): string[] {
    let res: string[] = [words[0]]
    let i: number = 0
    let len: number = words.length
    while (++i < len) {
        let L: string, R: string

        L = words[i - 1].split('').sort().join('')
        R = words[i].split('').sort().join('')
        while (L == R) {
            ++i
            if (i > len - 1) {
                break
            }
            R = words[i].split('').sort().join('')
        }
        if (i > len - 1) {
            break
        }
        res.push(words[i])
    }
    return res
};
