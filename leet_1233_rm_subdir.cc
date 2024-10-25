class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end());
        int i = 0;
        vector<string> res{folder[i]};
        while (++i < folder.size())
        {
            string parent = res.back() + "/";
            string substr = folder[i].substr(0, parent.size());
            // cout << parent << ' ' << substr << endl;
            if (parent != substr)
                res.push_back(folder[i]);
        }
        return res;
    }
};
