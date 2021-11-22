from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        list_size = len(nums)
        for i in range(list_size):
            nums[nums[i]-1] -= nums[nums[i]-1]
            print(nums)
        return [i+1 for i in range(list_size) if nums[i] > 0]


s = Solution()

ans = s.findDisappearedNumbers([4,3,2,7,8,2,3,1])

print(ans)