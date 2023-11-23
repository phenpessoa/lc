package main

import (
	"math"
	"math/rand"
	"testing"
)

type solver = func([]int) int

var (
	sink  int
	nums1 []int
	nums2 []int
	nums3 []int
)

func init() {
	genNums()
}

func genNums() {
	const n = 100000

	nums1 = make([]int, n)
	nums2 = make([]int, n)
	nums3 = make([]int, n)
	for i := 0; i < n; i++ {
		if i > 0 {
			nums1[i] = n - i
		}
		nums2[i] = rand.Intn(math.MaxInt32-math.MinInt32) + math.MinInt32
		nums3[i] = i + 1
	}
}

func runBenchmark(b *testing.B, solver solver, nums []int) {
	b.ReportAllocs()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		sink = solver(nums)
	}
}

func BenchmarkOne_Nums1(b *testing.B)   { runBenchmark(b, firstMissingPositive1, nums1) }
func BenchmarkOne_Nums2(b *testing.B)   { runBenchmark(b, firstMissingPositive1, nums2) }
func BenchmarkOne_Nums3(b *testing.B)   { runBenchmark(b, firstMissingPositive1, nums3) }
func BenchmarkTwo_Nums1(b *testing.B)   { runBenchmark(b, firstMissingPositive2, nums1) }
func BenchmarkTwo_Nums2(b *testing.B)   { runBenchmark(b, firstMissingPositive2, nums2) }
func BenchmarkTwo_Nums3(b *testing.B)   { runBenchmark(b, firstMissingPositive2, nums3) }
func BenchmarkThree_Nums1(b *testing.B) { runBenchmark(b, firstMissingPositive3, nums1) }
func BenchmarkThree_Nums2(b *testing.B) { runBenchmark(b, firstMissingPositive3, nums2) }
func BenchmarkThree_Nums3(b *testing.B) { runBenchmark(b, firstMissingPositive3, nums3) }
