class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        return [
            twopass,
        ][0](rectangles)

def twopass(rectangles: List[List[int]]) -> bool:
    hori,vert = [],[]
    for a,b,c,d in rectangles:
        hori.append((a,c))
        vert.append((b,d))
    hori.sort()
    ok,R = 0,hori[0][1] # 1
    for l,r in hori:
        if R <= l:
            ok += 1
        if ok > 1:
            return True
        R = max(R,r)
    vert.sort()
    ok,R = 0,vert[0][1] # 2
    for l,r in sorted(vert):
        if R <= l:
            ok += 1
        if ok > 1:
            return True
        R = max(R,r)
    return False 
    
