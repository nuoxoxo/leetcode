impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut seen = vec![false; 26];
        let mut count = vec![0; 26];
        let mut res = String::new();
        let a = 'a' as u8;

        for c in s.chars() {
            let idx = (c as u8 - a) as usize;
            count[idx] += 1;
        }

        for c in s.chars() {
            let idx = (c as u8 - a) as usize;

            if !seen[idx] {
                while !res.is_empty() && res.chars().last().unwrap() > c && count[(res.chars().last().unwrap() as u8 - a) as usize] > 1 {
                    let last_char = res.pop().unwrap();
                    let last_idx = (last_char as u8 - a) as usize;
                    seen[last_idx] = false;
                    count[last_idx] -= 1;
                }
                seen[idx] = true;
                res.push(c);
            } else {
                count[idx] -= 1;
            }
        }

        res
    }
}
