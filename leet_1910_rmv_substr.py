class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        return [
            using_find,
            using_replace,
        ][1](s,part)

def using_replace(s:str, p:str) -> str:
    while p in s:
        s = s.replace(p, '', 1) # one rep at a time
    return s

def using_find(s:str, p:str) -> str:
    while 42:
        pos = s.find(p)
        if pos < 0:
            break
        s = s[:pos] + s[pos + len(p):]
    return s
