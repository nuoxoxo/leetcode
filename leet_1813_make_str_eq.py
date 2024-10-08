class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        L = deque(sentence1.split())
        R = deque(sentence2.split())
        while L and R and L[0] == R[0]:
            L.popleft()
            R.popleft()
        while L and R and L[-1] == R[-1]:
            L.pop()
            R.pop()
        return not L or not R
        
