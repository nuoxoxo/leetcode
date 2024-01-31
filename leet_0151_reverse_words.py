class Solution:
    def reverseWords(self, s: str) -> str:
        temp = s.split()
        return ' '.join(temp[::-1])
