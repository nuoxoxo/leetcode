// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque; // added: deque

impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut res = Vec::new();
        let mut dq = VecDeque::new();
        dq.push_back(root.unwrap()); // unwrap
        while ! dq.is_empty() {
            let size = dq.len(); // len()
            let temp: i64 = (0..size)
            .map(|_| {
                let node = dq.pop_back().unwrap();
                let node = node.borrow(); // needs a second let keyword
                if let Some(ref L) = node.left { // if let Some(ref)
                    dq.push_front(L.clone()); // clone
                };
                if let Some(ref R) = node.right {
                    dq.push_front(R.clone());
                };
                node.val as i64
            })
            .sum();
            res.push(temp as f64 / size as f64);
        }
        res // return w/o keyword
    }
}


// 
