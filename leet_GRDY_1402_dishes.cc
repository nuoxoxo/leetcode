class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        // Greedy

        sort(satisfaction.begin(),satisfaction.end());

        int len = satisfaction.size();        
        int tmp = 0;
        int res = 0;
        int cur = 0;
        int i = len;
        while (--i > -1)
        {
            cur += tmp + satisfaction[i];
            if (cur < 1)
                break ;
            tmp += satisfaction[i];
            res = max(res, cur);
        }
        return res;
    }
};;
