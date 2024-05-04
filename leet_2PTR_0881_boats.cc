class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {

        // [1,2,4,5]
        // [3,2,2,1]
        sort(begin(people), end(people));
        int N = people.size();
        int l = 0, r = N - 1;
        int res = 0;
        while (l <= r)
        {
            res++;
            if (people[l] + people[r] <= limit)
            {
                l += 1;
                r -= 1;
            }
            else
            {
                r -= 1;
            }
        }
        return res;
    }
};
