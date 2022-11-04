class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int>  mp;
        vector<pair<string, int>>   vc;
        vector<string>              res;

        for (string s: words)
            mp[s]++;
        copy(mp.begin(), mp.end(),
            back_inserter<vector<pair<string, int>>> (vc));
        sort(vc.begin(), vc.end(),
             [] (const pair<string, int>& a, const pair<string, int>& b)
             {
                 if (a.second == b.second)
                     return (a.first < b.first);
                 return a.second > b.second;
             });
        for (pair p: vc)
        {
            res.push_back(p.first);
            if (--k == 0)
                break ;
        }
        return res;
    }
};
