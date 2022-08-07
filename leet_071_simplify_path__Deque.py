class Solution:
    def simplifyPath(self, path: str) -> str:
        res = '/'
        D = deque()
        temp = path.split('/')
        temp = list(filter(None, temp))
        for elem in temp:
            if elem == '..':
                if D:
                    D.pop()
            elif elem != '.':
                D.append(elem)
        while D:
            res += D.popleft()
            if D:
                res += '/'
        return res 
