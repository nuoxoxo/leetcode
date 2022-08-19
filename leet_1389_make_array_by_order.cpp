class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
    {
        vector<int> r;
        int i = -1;

        while (++i < index.size())
        {
            // cout << nums[i] << " is put to pos of " << index[i] << endl;
            r.insert(r.begin() + index[i], nums[i]);
            // vip(r);
        } 
        return r;
    }

    void vip(vector<int> n)
    {
        for (int e : n)
            cout << e << ' ';
        cout << endl;
    }
};
