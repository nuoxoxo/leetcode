class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>::iterator   it;
        vector<int>             temp;
        for (int n: nums)
        {
            it = std::lower_bound(temp.begin(), temp.end(), n);
            if (it != temp.end())
                *it = n;
            else    
                temp.push_back(n);
        }
        return (int) temp.size();
    }
};
