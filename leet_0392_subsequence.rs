impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        if s.is_empty() {
            return true;
        }

        let (mut i, mut j) = (0, 0);
        let (ls, lt) = (s.len(), t.len());

        while i < ls && j < lt {
            if s.chars().nth(i) == t.chars().nth(j) {
                i += 1;
            }
            j += 1;
            if i == ls {
                return true;
            }
        }

        false
    }
}
