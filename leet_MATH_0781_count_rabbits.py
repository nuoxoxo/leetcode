class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        answers.sort()
        res,curr = 0,0 # curr is surplus
        for i,n in enumerate(answers):
            # unique
            if n == 0:
                res += 1
            elif n == answers[i - 1] and i != 0 and curr != 0:
                #   if 2 rabbits claim a same number, 
                #   then we reduce our "unique reserve number"(ie. curr)
                #   
                #   if curr is already one then
                #   we count these n rabbits as entirely unique
                #   and add in +1 (the claimer itself)
                curr -= 1
            else:
                curr = n
                res += curr + 1
        return res
