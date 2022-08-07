class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        def dfs(op:int,cp:int,s:str,res:List[str]):
            if op is 0 and cp is 0:
                res.append(s)
                return
            if op is not 0:
                s += '('
                dfs(op - 1, cp, s, res)
                s = s[:-1]
            if op < cp:
                s += ')'
                dfs(op, cp - 1, s, res)
                s = s[:-1]

        res = []
        s = ""
        dfs(n, n, s, res)
        return res
