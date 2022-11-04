class Solution {
public:
    
    static int cmp(pair<string, int>& a, pair<string, int>& b)
    {
        if ((a.second > b.second) || (a.second == b.second && a.first < b.first))
            return 1;
        return 0;
    }

    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int>  mp;
        vector<pair<string, int>>   vc;
        vector<string>              res;

        for (string s: words)
            mp[s]++;
        copy(mp.begin(), mp.end(),
            back_inserter<vector<pair<string, int>>> (vc));
        sort(vc.begin(), vc.end(), & cmp);
        for (pair p: vc)
        {
            res.push_back(p.first);
            if (--k == 0)
                break ;
        }
        return res;
    }
};
