class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int>::iterator   it;
        unordered_map<int, int>             E;

        for (int n: nums)   E[n]++ ;
        it = E.begin();
        while (it != E.end())
        {
            if(it->second ^ 3)
                break;
            it ++;
        }
        return it->first ;
    }
};
