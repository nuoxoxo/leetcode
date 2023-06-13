use std::collections::HashMap;

impl Solution {

    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let mut dict: HashMap<String, i32> = HashMap::new();
        let len = grid.len();
        let mut cols: Vec<String> = vec![String::new(); len];
        let mut res = 0;

        for nums in & grid {
            let mut s = String::new();

            for i in 0..len {
                let n = nums[i];
                s += & format!(" {}", n);
                cols[i] += & format!(" {}", n);
            }
            if let Some(value) = dict.get_mut(& s) {
                * value += 1;
            } else {
                dict.insert(s.clone(), 1);
            }
            // println!("{} {}", s, dict[&s]);
        }

        for c in & cols {
            if let Some(value) = dict.get(c) {
                res += * value;
            }
        }
        // println!("{:?}", dict);

        res

    }
}
