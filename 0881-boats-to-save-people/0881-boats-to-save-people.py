class Solution:
    def numRescueBoats(self, people: list[int], limit: int) -> int:
        people.sort(reverse = True)
        print(people)
        ans = 0
        left = 0
        right = len(people)-1
        while left <= right:
            ans += 1
            temp = limit - people[left]
            left += 1
            if left > right:
                break
            if people[left] <= temp:
                left += 1
            elif people[right] <= temp:
                right -= 1
        return ans