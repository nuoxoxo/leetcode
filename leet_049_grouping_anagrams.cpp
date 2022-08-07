class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> d;
        vector<vector<string>>      v;
        for (string s: strs)
        {
            string  temp = s;
            sort(temp.begin(), temp.end());
            d[temp].push_back(s);
        }
        
        map<string, vector<string>>::iterator   it = d.begin();
        while (it != d.end())
        {
            v.push_back(it->second);
            ++ it ;
        }
        return v;
    }
};
