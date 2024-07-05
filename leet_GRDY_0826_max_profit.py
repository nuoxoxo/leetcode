class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        LM = [(level, money) for level, money in zip(difficulty, profit)]
        LM.sort(key=lambda x : x[0])
        Q = collections.deque(LM)
        res = 0
        curr = 0 # current best
        for person in sorted(worker):
            while Q and person >= Q[0][0]:#.level:
                _, money = Q.popleft()
                curr = max(curr, money)#.money)
            print('accepted/ ', person, curr)
            res += curr
        return res
