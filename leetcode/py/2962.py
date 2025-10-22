class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        ans = 0
        max_elem = max(nums)
        max_cnt = 0

        l = 0

        for r in range(len(nums)):
            if nums[r] == max_elem:
                max_cnt += 1

            while max_cnt == k:
                ans += len(nums) - r
                if nums[l] == max_elem:
                    max_cnt -= 1
                l += 1

        return ans
