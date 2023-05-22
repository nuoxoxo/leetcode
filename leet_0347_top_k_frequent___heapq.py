class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for n in nums:
            try:
                d[n] += 1
            except:
                d[n] = 1
        q = []
        for n in d:
            q.append((d[n], n))
        heapq.heapify(q)
        res = []
        for n in heapq.nlargest(k, q):
            res.append(n[1])
        return res
