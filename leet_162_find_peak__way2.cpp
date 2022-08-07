class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        vector<int> copy = nums ;

        sort(copy.begin(), copy.end(), greater<int>());
        return distance(nums.begin(), find(nums.begin(), nums.end(), copy[0])) ;
    }
};
