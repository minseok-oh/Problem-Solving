func solution(n int, m int, section []int) int {
    var result, here int = 0, 0
    for i := 0; i < len(section); i++ {
        if section[i] < here {
            continue
        } else {
            here = section[i] + m
            result += 1
        }
    }
    return result
}