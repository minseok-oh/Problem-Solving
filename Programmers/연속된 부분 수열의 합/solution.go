func findTargetSubArray(sequence []int, k int) (int, int) {
    var left, right int = 0, 0
    var leftRes, rightRes int = 0, 10000001
    var sum int = sequence[0]
    
    var end int = len(sequence)
    for right < end && left <= right {
        if sum < k {
            right += 1
            if right != end {
                sum += sequence[right]
            }
        } else if sum > k {
            sum -= sequence[left]
            left += 1
        } else {
            if (rightRes - leftRes > right - left) {
                leftRes = left
                rightRes = right
            }
            
            right += 1
            if right != end {
                sum += sequence[right]
            }
        }
    }
    
    return leftRes, rightRes
}

func solution(sequence []int, k int) []int {
    var left, right int = findTargetSubArray(sequence, k)
    return []int{left, right}
}