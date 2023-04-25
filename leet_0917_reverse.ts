function reverseOnlyLetters(s: string): string {
    // let a = s.split('') // way 1
    // let a = Array.from(s) // way 2
    let a = [...s] // way 3
    console.log(a)
    let l = 0, r = a.length - 1
    while (l < r) {
        if (isalpha(a[l]) && isalpha(a[r])) {
            let c = a[l]
            a[l] = a[r]
            a[r] = c
            l += 1
            r -= 1
        } else if ( ! isalpha(a[l])) {
            l += 1
        } else if ( ! isalpha(a[r])) {
            r -= 1
        }
    }
    return a.join('')
};

function isalpha(s: string) {
    if (s.match(/[a-z]/i) || s.match(/[A-Z]/i))
        return true
    return false
}
