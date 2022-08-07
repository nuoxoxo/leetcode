class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        vector<int>     res;
        int             first = -1;
        int             last;
        int             n = nums.size();

        sort(nums.begin(), nums.end());
        while (++first < n && nums[first] ^ target)
            ;
        if (first == n) /* no match */
            return res;
        last = first;
        while (nums[last] == target && ++last < n)
            ;
        if ((first + 1 == last && last != n) || first == n - 1)
            return {first}; /* onlyt one match . or the match is at the end */
        if (first + 2 == last)
            return {first, last - 1}; /* two matches*/
        while (first < last)
            res.push_back(first++);
        return res;
    }
};
