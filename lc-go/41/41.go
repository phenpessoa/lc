package main

func firstMissingPositive1(nums []int) int {
outer:
	for i := 0; i < len(nums)+1; i++ {
		for _, n := range nums {
			if n == i {
				continue outer
			}
		}
		return i
	}
	return len(nums) + 1
}

func firstMissingPositive2(nums []int) int {
	m := make([]bool, len(nums)+1)
	for _, n := range nums {
		if n > 0 && n <= len(nums) {
			m[n] = true
		}
	}

	for i := 1; i < len(nums)+1; i++ {
		if !m[i] {
			return i
		}
	}

	return len(nums) + 1
}

func firstMissingPositive3(nums []int) int {
	for i := 0; i < len(nums); {
		cur := nums[i]
		if cur > 0 && cur <= len(nums) && nums[cur-1] != cur {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
			continue
		}
		i++
	}

	for i := 1; i < len(nums)+1; i++ {
		if nums[i-1] != i {
			return i
		}

	}

	return len(nums) + 1
}
