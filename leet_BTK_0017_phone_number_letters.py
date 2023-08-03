class Solution:
    # buttons = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        buttons = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        res = []
        test = ""
        self.backtracking(buttons, digits, test, res, 0)
        return res
    def backtracking(self, buttons: List[str], digits: str, test: str, res: List[str], index: int):
        if index != len(digits):
            n = int(digits[index])
            for i in range(len(buttons[n])):
                test += buttons[n][i]
                self.backtracking(buttons, digits, test, res, index + 1)
                test = test[:-1]
        else:
            res.append(test)
