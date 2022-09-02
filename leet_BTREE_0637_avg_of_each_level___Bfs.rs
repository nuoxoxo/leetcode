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
            let mut temp = 0_f64; // 0_f64
            for _ in 0..size {
                let node = dq.pop_back().unwrap();
                temp += node.borrow().val as f64; // borrow()
                if let Some(L) = & node.borrow().left { // if let Some(_)
                    dq.push_front(L.clone()); // clone
                } 
                if let Some(R) = & node.borrow().right {
                    dq.push_front(R.clone());
                }; 
                // the above semicolon is crucial, otherwise err:
                // "node dropped here while still borrowed"
            }
            res.push(temp / size as f64);
        }
        res // return w/o keyword
    }
}


// 
