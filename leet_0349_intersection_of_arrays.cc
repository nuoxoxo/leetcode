class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int>        st;

        for (int n1: nums1)
        {
            for (int n2: nums2)
            {
                if (n1 == n2)
                    st.insert(n1);
            }
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};
