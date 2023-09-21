function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let N:number[] = nums1.concat(nums2)
    N.sort((a, b) => a - b)
    let len = N.length
    let mid = Math.floor(len / 2)
    if (len % 2) {
        return N[mid]
    }
    return (N[mid - 1] + N[mid]) / 2
};
