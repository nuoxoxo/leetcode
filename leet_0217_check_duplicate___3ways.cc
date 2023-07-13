class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        //  method 1
        /*
        unordered_map<int, int> M;

        for (int i = 0; i < nums.size(); i++)
        {
            M[nums[i]]++;
            if (M[nums[i]] > 1) return (true);
        }
        return (false);
        */


        //  method 2
        //return (nums.size() > set(nums.begin(), nums.end()).size());


        //  method 3 :: fastest
        sort(nums.begin(), nums.end());
        return (adjacent_find(nums.begin(), nums.end()) != nums.end());
    }
};
