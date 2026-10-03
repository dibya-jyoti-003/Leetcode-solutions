class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        left ,right = 0, n-1
        while left < right:
            mid = left + (right-left)//2
            if nums[left]<=nums[mid] and nums[mid+1]<=nums[right]:
                return min(nums[left], nums[mid+1])
            elif nums[left]<nums[mid]:
                left = mid
            else :
                right = mid
        return nums[0]