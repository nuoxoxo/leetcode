class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        return [
            self.Best_solution,
            # self.Space_heavy_combo,
        ][ 0 ]( nums )

    def Best_solution(self, nums: List[int]) -> int:
        D = defaultdict(int)
        times, top = 0, -1
        for n in nums:
            D[n] += 1
            if D[n] > top:
                top = D[n]
                times = 0
            if D[n] == top:
                times += 1
        return top * times

    def Space_heavy_combo(self, nums: List[int]) -> int:
        D = dict(sorted(Counter(nums).items(), key=lambda x:x[1], reverse=True))
        top = list(D.items())[0][1]
        res = 0
        for v in D.values():
            if v != top:
                break
            res += top
        return res
