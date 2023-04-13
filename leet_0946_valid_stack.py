class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        idx = 0
        a = []
        for n in pushed:
            a.append(n)
            while a and a[-1] == popped[idx]:
                a.pop()
                idx += 1
        return not a
