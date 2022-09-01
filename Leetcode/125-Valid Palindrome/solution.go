package main

func isPalindrome(s string) bool {
	var strs []rune
	for _, char := range s {
		if '0' <= char && char <= '9' {
			strs = append(strs, char)
		} else if 'A' <= char && char <= 'Z' {
			strs = append(strs, char-'A'+'a')
		} else if 'a' <= char && char <= 'z' {
			strs = append(strs, char)
		}
	}

	left, right := 0, len(strs)-1
	for left < right {
		if strs[left] != strs[right] {
			return false
		}
		left += 1
		right -= 1
	}
	return true
}
