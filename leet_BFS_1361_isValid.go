func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    if n == 1 {
		return len(leftChild) == 1 && leftChild[0] == -1 &&
			len(rightChild) == 1 && rightChild[0] == -1
	}

	var R []int
	var i int
    Lset := make(map[int]bool)
	Rset := make(map[int]bool)
	node := -1
    i = -1
    for i < len(leftChild) - 1 {
        i++
        Lset[leftChild[i]] = true
    }

    i = -1
    for i < len(rightChild) - 1 {
        i++
        Rset[rightChild[i]] = true
    }

	for node < n - 1 {
		node++
		if !Lset[node] && !Rset[node] {
            if leftChild[node] > -1 || rightChild[node] > -1 {
			    R = append(R, node)
                // fmt.Println(R)
            }
		}
	}

	if len(R) != 1 {
        // fmt.Println(R)
		return false
	}

	root := R[0]
	dq := []int{root}
	seen := make(map[int]bool)

    // fmt.Println("here 1")

	for len(dq) > 0 {
		size := len(dq)
		i = -1
		for i < size - 1 {
			i++
			node := dq[0]
            dq = dq[1:]
			if node == -1 {
				continue
			}
			if seen[node] {
				return false
			}
			seen[node] = true
			dq = append(dq, leftChild[node])
			dq = append(dq, rightChild[node])
		}
	}

	return len(seen) == n
}
