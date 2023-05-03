function findDifference(nums1: number[], nums2: number[]): number[][] {
    let n1 = [...new Set(nums1)]
    let n2 = [...new Set(nums2)]
    return [
        n1.filter((n) => {return n2.indexOf(n) < 0;}), 
        n2.filter((n) => {return n1.indexOf(n) < 0;})
    ]
};

