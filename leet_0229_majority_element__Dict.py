class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        s = len(nums) // 3
        m = dict()
        r = []
        for n in nums:
            m[n] = m.get(n, 0) + 1
        for i in m:
            if m[i] > s:
                r.append(i)
        return r
        
