function mySqrt(x: number): number {
    
    const Solutions: ((x: number) => number)[] = [
        Solution_Binary_Search,
        Solution_Newton,
        Solution_Bruteforce,
    ]
    const randint = Math.floor(Math.random() * Solutions.length)
    return Solutions[ randint ]( x )
};

const Solution_Binary_Search = (x : number): number => {
    console.log('/Solution_Binary_Search')
    let res = 1
    let [L, R] = [0, x]
    while (L <= R) {
        let mid = Math.floor((R - L) / 2) + L
        let sq = mid * mid
        if (sq == x) {
            return mid
        }
        if (sq > x) {
            R = mid - 1
        } else {
            res = mid
            L = mid + 1
        }
    }
    return res
}

const Solution_Newton = (x : number): number => {
    console.log('/Solution_Newton')
    if (x == 0 || x == 1) {
        return x
    }
    let res = x
    while (res * res > x) {
        res = Math.floor((res + Math.floor(x / res)) / 2)
    }
    return res
}

const Solution_Bruteforce = (x : number): number => {
    console.log('/Solution_Bruteforce')
    if (x == 0 || x == 1) {
        return x
    }
    let res = 1
    while (res * res <= x && (res+1) * (res+1) <= x) {
        res += 1
    }
    return res
}

