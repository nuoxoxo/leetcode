/**
 Do not return anything, modify arr in-place instead.
 */
function duplicateZeros(arr: number[]): void {
    let i = 0
    while (i < arr.length) {
        if (arr[i] == 0) {
            arr.splice(i + 1, 0, 0)
            arr.pop()
            i += 2
        } else {
            ++i
        }
    }
};
