class Solution:
    def reverseParentheses(self, s: str) -> str:
        return [
            Using_stack,
        ][0](s)

def Using_stack(s:str) -> str:
    N = len(s)
    Q = deque()
    print('before/', s)
    # l2r = {} # mapping index of a left ( to that of a right one
    for i, c in enumerate(s):
        if c is '(':
            Q.append(i)
        elif c is ')':
            assert Q
            L = Q.pop()
            # print(L + 1, i)
            # print('/1 ', s[:L], s[L + 1 : i], s[i + 1:])
            # print('1/ ', s)

            s = s[:L] + s[L:i][::-1] + s[i:]
            # print('2/ ', s)
    return ''.join(c for c in s if c.isalpha())

# case 3
# before/ (ed(et(oc))el)
# 7 9
# after/1  (ed(et oc )el)
# after/2  (ed(etco)el)
# 4 10
# after/1  (ed etco)e )
# after/2  (ede)octe)
# 1 13

# case 4
# before/ a(bcdefghijkl(mno)p)q
# 14 17
# after/1  a(bcdefghijkl mno p)q
# after/2  a(bcdefghijklonmp)q
# 2 19
# after/1  a bcdefghijklonmp)q 
# after/2  aq)pmnolkjihgfedcb

