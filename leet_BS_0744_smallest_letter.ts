function nextGreatestLetter(letters: string[], target: string): string {
    let n: number = letters.length
    let L:number = 0
    let R:number = n
    while (L < R) {
        let mid:number = Math.floor((R - L) / 2) + L
        if (letters[mid].charCodeAt(0) <= target.charCodeAt(0))
            L = mid + 1
        else
            R = mid
    }
    // if (R == n)
    //     return letters[0]
    // return letters[R]
	return letters[R % n]
};
