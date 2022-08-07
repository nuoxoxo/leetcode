class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        lp = len(popped)
        d = deque()
        i = 0
        for p in pushed:
            d.append(p)
            while len(d) is not 0 and i < lp and d[-1] == popped[i]:
                d.pop()
                i += 1
        return i == lp
