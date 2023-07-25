function peakIndexInMountainArray(arr: number[]): number {

    let L: number = 0
    let R: number = arr.length - 1
    while (L <= R) {
        let mid: number = Math.floor((R - L + 1) / 2) + L
        if (arr[mid] < arr[mid + 1]) {
            L = mid + 1
        } else {
            R = mid - 1
        }
    }
    return L
};
