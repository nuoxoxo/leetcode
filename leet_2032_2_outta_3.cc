class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        set<int>    s;
        for (int n: nums1)
        {
            // if (find(nums2.begin(), nums2.end(), n) != nums2.end() || find(nums3.begin(), nums3.end(), n) != nums3.end())
            if (count(nums2.begin(), nums2.end(), n) || count(nums3.begin(), nums3.end(), n))
            s.insert(n);
        }
        for (int n: nums2)
        {
            // if (find(nums3.begin(), nums3.end(), n) != nums3.end())
            if (count(nums3.begin(), nums3.end(), n))
                s.insert(n);
        }
        return vector<int>(s.begin(), s.end());
    }
};
