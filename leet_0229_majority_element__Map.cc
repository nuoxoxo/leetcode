class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        map<int, int>           m ;
        vector<int>             r ;
        int                     len ;
    
        for (int n: nums)
            m[n] += 1;
        len = nums.size() / 3;
        for (std::pair it: m)
        {
            if (it.second > len)
                r.push_back(it.first) ;
        }
        return r ;
    }
};
