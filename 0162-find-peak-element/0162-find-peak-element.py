class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        n = len(nums)
        left, right =0, n-1
        while left <= right:
            mid = left + (right-left)//2
            if (mid+1>=n or nums[mid]>nums[mid+1]) and (mid<=0 or nums[mid]>nums[mid-1]):
                return mid
            elif mid>0 and nums[mid] < nums[mid-1]:
                right = mid-1
            else :
                left = mid+1
        return 0