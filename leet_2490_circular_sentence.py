class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        # A = [_.lower() for _ in sentence.split()]
        A = sentence.split()
        if A[0][0] != A[-1][-1]:
            return False
        N = len(A)
        for i in range(N - 1):
            if A[i][-1] != A[i + 1][0]:
                return False
        return True
