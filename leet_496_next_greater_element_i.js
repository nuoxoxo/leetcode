var nextGreaterElement = function(nums1, nums2) {
    let i = -1, len1 = nums1.length, len2 = nums2.length
    let st = []
    let mp = new Map()
    let res = new Array(len1)

    res.fill(-1)
    while (++i < len2){
        if (!st.length || st[0] > nums2[i])
            st.unshift(nums2[i])
        else{
            mp.set(st[0], nums2[i])
            st.shift()
            --i
        }
    }
    i = -1
    while (++i < len1){
        if (mp.has(nums1[i]))
            res[i] = mp.get(nums1[i])
    }
    return res 
};
