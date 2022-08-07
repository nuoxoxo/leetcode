class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target)
    {
        int     r, c, i, j, k, count;

        r = matrix.length;
        if (r == 0)
            return (r);
        c = matrix[0].length;
        count = 0;
        i = -1;
        while (++i < r)
        {
            int[]   temp = new int[c];

            Arrays.fill(temp, 0);
            j = i + 1;
            while (--j > -1)
            {
                k = -1;
                while (++k < c)
                    temp[k] += matrix[j][k];
                count += subarray_sum(temp, target);
            }
        }
        return (count);
    }

    int subarray_sum(int[] arr, int tar)
    {
        HashMap<Integer, Integer>   mp;
        int     sum, res, len, i;

        mp = new HashMap<Integer, Integer>();
        len = arr.length;
        res = 0;
        sum = 0;
        i = -1;
        while (++i < len)
        {
            sum += arr[i];
            if (sum == tar)
                res++;
            if (mp.containsKey(sum - tar))
                res += mp.get(sum - tar);
            if (mp.containsKey(sum))
                mp.put(sum, mp.get(sum) + 1);
            else
                mp.put(sum, 1);
        }
        return (res);
    }
}
