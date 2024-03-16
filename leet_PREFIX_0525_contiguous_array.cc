class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> mp ;
        int                     max_length;
        int                     count;
        int                     i;

        max_length = count = 0;
        i = -1;
        while (++i < (int) nums.size())
        {
            if (!nums[i])   --count ;
            else            ++count ;
            if (!count)     max_length = i + 1;
            else
            {
                if (mp.find(count) == mp.end())
                    mp[count] = i;
                else
                {
                    int tmp = i - mp[count] ;
                    max_length = max_length > tmp ? max_length : tmp ;
                }
            }
        }
        return max_length ;
    }
};
