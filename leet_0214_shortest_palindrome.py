class Solution:
    def shortestPalindrome(self, s: str) -> str:
        return [
            Bruteforce,
        ][0](s)

def Bruteforce(s: str) -> str:
    res = ''
    rev = s[::-1]
    N = len(s)
    """
    idea/ we trace a pointer i, so that right of pointer of rev
        is eq. to the left of pointer of src
    rev:          src:
    cbazzzyyyxxx  xxxyyyzzzabc
             ^^^  ^^^
             i
    # here an i is found so that rev[i:] == src[:N - i]
    # so that the result should be 
    # cbazzzyyy - rev[:i]
    # + 
    # xxxyyyzzzabc - the entire src

    eg/

    rev:     s:
    aaacecaa aacecaaa 
    ^aacecaa aacecaa^ found
    a + aacecaaa --- result

    rev: s:
    dcba abcd
    ^cba abc^
     ^ba ab^
      ^a a^ ----- found
    dcb + abcd -- result
    """
    for i in range(N + 1):
        # print(i, rev[i:], s[:N - i])
        if rev[i:] == s[:N - i]:
            res = rev[:i] + s
            break
    return res
