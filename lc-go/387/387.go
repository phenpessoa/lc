package main

func firstUniqChar1(s string) int {
outer:
	for i, r := range s {
		for j, rr := range s {
			if i != j && r == rr {
				continue outer
			}
		}
		return i
	}
	return -1
}

func firstUniqChar2(s string) int {
	m := make(map[rune]int, 26)
	for _, r := range s {
		m[r]++
	}
	for i, r := range s {
		if m[r] == 1 {
			return i
		}
	}
	return -1
}

func firstUniqChar3(s string) int {
	m := [26]int{}
	for i := range s {
		m[s[i]-'a']++
	}
	for i := range s {
		if m[s[i]-'a'] == 1 {
			return i
		}
	}
	return -1
}
