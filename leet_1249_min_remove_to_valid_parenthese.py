class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        d = deque()
        a = []
        for i in range(len(s)):
            if s[i] == '(':
                d.append(i)
            if s[i] == ')':
                if not d:
                    a.append(i)
                else:
                    d.pop()
        rule = set(d).union(set(a))
        temp = list(s)
        for i in rule:
            temp[i] = ''
        return ''.join(temp)
