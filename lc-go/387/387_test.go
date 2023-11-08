package main

import (
	"strings"
	"testing"
)

const (
	smallStringRepeating    = "abcdefghjiklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"
	smallStringNonRepeating = "bcdefghjiklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"
)

var (
	largeStringRepeating    = "abcdefghjiklmnopqrstuvwxyz" + strings.Repeat("z", 1000000) + "zyxwvutsrqponmlkjihgfedcba"
	largeStringNonRepeating = "bcdefghjiklmnopqrstuvwxyz" + strings.Repeat("z", 1000000) + "zyxwvutsrqponmlkjihgfedcba"

	sink int
)

type solver = func(s string) int

func runBenchmark(b *testing.B, solver solver, s string) {
	b.ReportAllocs()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		sink = solver(s)
	}
}

func BenchmarkOne_SmallRepeating(b *testing.B) { runBenchmark(b, firstUniqChar1, smallStringRepeating) }
func BenchmarkOne_SmallNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar1, smallStringNonRepeating)
}
func BenchmarkOne_LargeRepeating(b *testing.B) { runBenchmark(b, firstUniqChar1, largeStringRepeating) }
func BenchmarkOne_LargeNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar1, largeStringNonRepeating)
}

func BenchmarkTwo_SmallRepeating(b *testing.B) { runBenchmark(b, firstUniqChar2, smallStringRepeating) }
func BenchmarkTwo_SmallNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar2, smallStringNonRepeating)
}
func BenchmarkTwo_LargeRepeating(b *testing.B) { runBenchmark(b, firstUniqChar2, largeStringRepeating) }
func BenchmarkTwo_LargeNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar2, largeStringNonRepeating)
}

func BenchmarkThree_SmallRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar3, smallStringRepeating)
}

func BenchmarkThree_SmallNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar3, smallStringNonRepeating)
}

func BenchmarkThree_LargeRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar3, largeStringRepeating)
}

func BenchmarkThree_LargeNonRepeating(b *testing.B) {
	runBenchmark(b, firstUniqChar3, largeStringNonRepeating)
}
