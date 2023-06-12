impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let len = nums.len();
        let mut i = 0;
        let mut e: Vec<String> = Vec::new();

        while i < len {
            let mut foo = false;
            let mut j = i;

            while j < len - 1 && nums[j] == nums[j + 1] - 1 {
                if !foo {
                    foo = true;
                }
                j += 1;
            }

            if !foo {
                e.push(nums[j].to_string());
            } else {
                e.push(format!("{}->{}", nums[i], nums[j]));
            }

            i = j + 1;
        }

        e
    }
}
