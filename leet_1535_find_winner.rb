# @param {Integer[]} arr
# @param {Integer} k
# @return {Integer}
def get_winner(arr, k)
    hi = arr.max
    len = arr.length
    if len <= k
        return hi
    end
    count = 0
    res = arr[0]
    i = 1
    while i < len
        if res < arr[i]
            count = 1
            res = arr[i]
        else
            count += 1
        end
        if count == k
            return res
        end
        i += 1
    end
    hi
end
