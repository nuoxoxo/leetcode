class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:        
        s = set()
        for m in emails:
            i = 0
            while m[i] != '@':
                i += 1
            temp = self.make(m[0 : i]) + '@' + m[i + 1 : -1]
            s.add(temp)
        return len(s)

    def make(self, o: str) -> str:
        s = ''
        i = 0
        while i < len(o) and o[i] != '+':
            if o[i] != '.':
                s += o[i]
            i += 1
        return s
