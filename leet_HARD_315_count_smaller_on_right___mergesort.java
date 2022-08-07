class Solution {
    class   Valkey
    {
        int val;
        int key;
        public  Valkey(int v, int k)
        {
            val = v;
            key = k;
        }
    }

    public List<Integer> countSmaller(int[] nums)
    {
        int             len = nums.length;
        Valkey[]        valkey = new Valkey[len];
        int[]           count = new int[len];
        List<Integer>   res = new ArrayList<>();
        int             i; 

        i = -1;
        while (++i < len)
        {
            valkey[i] = new Valkey(nums[i], i);
        }
        mergeSort(valkey, 0, len - 1, count);
        i = -1;
        while (++i < len)
        {
            res.add(count[i]);
        }
        return (res);
    }

    private void    mergeSort(Valkey[] valkey, int lo, int hi, int[] count)
    {
        int     mid;

        if (lo >= hi)
            return ;
        mid = lo + (hi - lo) / 2;
        mergeSort(valkey, lo, mid, count);
        mergeSort(valkey, mid + 1, hi, count);
        merge(valkey, lo, mid, mid + 1, hi, count);
    }

    //private void    merge(Valkey[] valkey, int lo_left, int lo_right, int hi_left, int hi_right, int[] count)
    private void    merge(Valkey[] valkey, int lo, int lo_end, int hi, int hi_end, int[] count)
    {
        int         len = hi_end - lo + 1;
        Valkey[]    sorted = new Valkey[len];
        int         lo_ptr = lo;
        int         hi_ptr = hi;
        int         right_counter = 0;
        int         i = 0;

        while (lo_ptr <= lo_end && hi_ptr <= hi_end)
        {
            if (valkey[lo_ptr].val > valkey[hi_ptr].val)
            {
                sorted[i] = valkey[hi_ptr];
                i++;
                hi_ptr++;
                right_counter++;
            }
            else
            {
                count[valkey[lo_ptr].key] += right_counter;
                sorted[i] = valkey[lo_ptr];
                i++;
                lo_ptr++;
            }
        }
        while (lo_ptr <= lo_end)
        {
            count[valkey[lo_ptr].key] += right_counter;
            sorted[i] = valkey[lo_ptr];
            i++;
            lo_ptr++;
        }
        while (hi_ptr <= hi_end)
        {
            sorted[i] = valkey[hi_ptr];
            i++;
            hi_ptr++;
        }
        System.arraycopy(sorted, 0, valkey, lo, len);
    }
}

