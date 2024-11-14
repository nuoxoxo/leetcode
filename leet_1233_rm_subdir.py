class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res = [folder[0]]
        for i in range(1, len(folder)):
            parent = res[-1] + '/'
            substr = folder[i][:len(parent)]
            # print(parent, substr)

            # parent - /a/
            # substr - /a/b [:len('/a/')] ---> /a/
            #   parent == substr: is sub-folder

            # 2ndsub - /c/d/e [:len('/a/')] ---> /c/
            #   parent == substr: not sub-folder

            if parent != substr:
                res.append(folder[i])
        return res
