class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        return [
            Using_groupby_and_catalan_number,
        ][0](expression)

# the number of ways to do parentheses in any expression
# is actually Catalan numbers
def Using_groupby_and_catalan_number(expression: str) -> List[int]:
    tokens = []
    # Goal:
    #   "21*3-42*5" ---convert--->
    #   [21, '*', 3, '-', 42, '*', 5]
    for ok, token in groupby(expression, lambda x: x in '+-*'):
        if ok:
            tokens.append(list(token)[0])
        else:
            tokens.append(int(''.join(list(token))))
    N = len(tokens)
    print(tokens)
    def f(L, R):
        if L == R:
            return [tokens[L]]
        res = []
        # Idea:
        #   every time there is an operator +-*, 
        #   we split the expression into two parts
        for mid in range(L + 1, R, 2):
            # due to the format of the tokenlist
            # operators are always at odd indices
            assert tokens[mid] in '+-*'
            left_res = f(L, mid - 1)
            right_res = f(mid + 1, R)
            for l in left_res:
                for r in right_res:
                    if tokens[mid] == '+':
                        res.append(l + r)
                    elif tokens[mid] == '-':
                        res.append(l - r)
                    elif tokens[mid] == '*':
                        res.append(l * r)
        return res
    return f(0, N - 1)
