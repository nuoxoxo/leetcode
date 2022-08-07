#* ******************************************** */
#*                                              */
#*              ~  ~  ~  ~  ~    ~              */
#*               ~    _ ~ _   o>                */
#*              ~  \ / \ / \ /  ~               */
#*               ~  ~      ~    ~               */
#*                                              */
#* ******************************************** */

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        M = {}
        for i in range(len(nums)):
            n = nums[i]
            if target - n in M:
                break
            M[n] = i
        return [M[target - n], i]
