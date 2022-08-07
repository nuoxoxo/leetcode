class Solution {
public:
    int distributeCandies(vector<int>& t){
        return (min((set<int>(t.begin(), t.end())).size(), t.size() / 2 )) ;
    }
};
