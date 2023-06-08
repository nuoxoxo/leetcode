class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        m = len(queries)
        prefix = 0
        pref = []
        res = [0 for _ in range(m)]
        for i in range(n):
            prefix += nums[i]
            pref.append(prefix)
        for i in range(m):
            tmp = 0
            for j in range(n):
                if pref[j] > queries[i]:
                    break
                tmp += 1
            res[i] = tmp
        return res
