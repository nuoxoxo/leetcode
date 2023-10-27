function longestPalindrome(s: string): string {
    let n:number = s.length
    if (n == 1)
        return s
    let head:number = 0
    let tail:number = 1
    let L: number
    let R: number
    let i = 0
    while (++i < n){
        L = i - 1
        R = i
        while (R < n && L > -1 && s[L] == s[R]){
            let dist = R - L + 1
            if (tail < dist){
                tail = dist
                head = L
            }
            L -= 1
            R += 1
        }
        L = i - 1
        R = i + 1
        while (R < n && L > -1 && s[L] == s[R]){
            let dist = R - L + 1
            if (tail < dist){
                tail = dist
                head = L
            }
            L -= 1
            R += 1
        }
    }
    // if (head == tail)
    // {
    //     if (head * 2 == n)
    //         return s.substring(head)
    //     return s[0]
    // }
    // 👆 No need to do this
    return s.substring(head, head + tail)
};
