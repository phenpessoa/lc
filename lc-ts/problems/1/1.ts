export function twoSum(nums: number[], target: number): number[] {
  const m: { [key: number]: number } = {};
  for (const [i, n] of nums.entries()) {
    const v = m[n];
    if (v !== undefined) {
      return [v, i];
    }
    m[target - n] = i;
  }
  return [];
}
