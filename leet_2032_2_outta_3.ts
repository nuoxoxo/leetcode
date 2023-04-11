function twoOutOfThree(nums1: number[], nums2: number[], nums3: number[]): number[] {
    let s = new Set<number>()
    for (let n of nums1) {
        if (nums2.includes(n) || nums3.includes(n)) {
            s.add(n)
        }
    }
    for (let n of nums2) {
        if (nums3.includes(n)) {
            s.add(n)
        }
    }
    return Array.from(s) 
};
