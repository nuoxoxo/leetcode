class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int>  mp;
        int                     res, start, curr, i;

        start = 0;
        curr = 0;
        i = -1;
        while (++i < fruits.size())
        {
            mp[fruits[i]]++;
            curr++;
            while (mp.size()>2)
            {
                mp[fruits[start]] -= 1;
                if (! mp[fruits[start]])
                    mp.erase(fruits[start]);
                --curr;
                ++start;
            }
            res = curr > res ? curr : res;
        }
        return res;
        
    }
};
