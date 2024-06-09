class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        map<int, int>   D ;
        D[0] = 1;
        int total = 0, count = 0;
        for (int n: nums)
        {
            total += n;
            if (D[total - k])
                count += D[total - k];
            if (D[total])
                ++ D[total] ;
            else
                D[total] = 1;
        }
        return count ;
    }
};
