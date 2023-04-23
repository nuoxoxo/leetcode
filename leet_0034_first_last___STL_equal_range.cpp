class Solution {
#define vii vector<int>::iterator
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        pair<vii, vii>  it;
        int             n, L;

        n = nums.size();
        if (!n)
            return {-1, -1};
        it = equal_range(nums.begin(), nums.end(), target);
        if (it.first == nums.end() || *it.first != target)
            return {-1, -1};
        L = (int) (it.first - nums.begin());
        if (it.second == nums.end())
            return {L, n - 1};
        if (it.second - 1 == it.first)
            return {L, L};
        return {L, (int) (it.second - nums.begin() - 1)};
    }
};

/*
[1,2,3,3,3,3,4,5,9]
3
[1,2,3]
1
[1,3]
1
[2,2]
3
[1]
1
[5,7,7,8,8,10]
8
[5,7,7,8,8,10]
6
[]
0
*/
