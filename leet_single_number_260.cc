class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> vect;
        int         i;
        
        if ( nums.size() == 2 ) return {nums[0], nums[1]};
        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1]) vect.push_back(nums[0]);
        i = -1;
        while (++i < nums.size() && vect.size() < 2)
        {
            if (i == nums.size() - 2)
                vect.push_back(nums[i + 1]);
            else if (nums[i] != nums[i + 1] && nums[i + 1] != nums[i + 2])
                vect.push_back(nums[i + 1]);
        }
        return (vect);
    }
};

/*
[1,2,1,3,2,5]
[0,1,2,2]
[0,1,1,2]
[0,0,1,2]
[-1,0]
[0,1]
*/
