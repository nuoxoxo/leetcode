class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int             n = nums.size(), i = 0, j;
        bool            more ;
        vector<string>  E;

        while (i < n)
        {
            more = false;
            j = i;
            while (j < n - 1 && nums[j] + 1 == nums[j + 1])
            {
                if (!more)  more = true ;
                j++;
            }
            if (more)
                E.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            else
                E.push_back(to_string(nums[i]));
            i = j + 1;
        }
        return E ;
    }
};
