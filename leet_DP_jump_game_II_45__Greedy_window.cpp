class Solution {
public:
    int jump(vector<int>& nums) {
        int steps, len, L, R;

        len = (int) nums.size();
        if (len == 1)       return 0;
        if (nums[0] >= len) return 1;
        steps = L = R = 0;
        while (R < len - 1)
        {
            int reach, i;

            i = L - 1; 
            reach = 0;
            while (++i < R + 1) reach = max(reach, i + nums[i]);
            L = R + 1;
            R = reach;
            steps ++;
        }
        return steps ;
    }
};

/*
[0]
[1,1,1,1]
[2,1,1,1,1]
[2,3,1,1,4]
[2,3,0,1,4]
*/
