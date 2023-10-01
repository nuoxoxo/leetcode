let n = nums.len();
    let mut pos = 0;
    let mut i = 0;
    let mut nums = nums;

    while i < n {
        if nums[i] % 2 == 0 {
            nums.swap(pos, i);
            pos += 1;
        }
        i += 1;
    }

    nums
