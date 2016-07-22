class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 3:
            return nums[0] + nums[1] + nums[2]

        nums.sort()

        t = nums[0] + nums[1] + nums[2]
        if t >= target:
            return t
        t = nums[-1] + nums[-2] + nums[-3]
        if t <= target:
            return t

        lens = len(nums)
        res = 0
        for i in range(lens-2):
            x = self.twoSumCloest(nums, target-nums[i], i+1, lens-1)

            res = nums[i] + x
            if res >= target:
                return res
        return res

    def twoSumCloest(self, nums, target, s, e):
        x = nums[s] + nums[e]

        if s - e == 1:
            return x
        delta = abs(target - x)
        while s < e:
            # x = nums[s] + nums[e]
            if x == target:
                return x

            if x < target:
                s += 1
            else:
                e -= 1

            if s >= e or abs(nums[s] + nums[e] - target) > delta:
                return x
            else:
                x = nums[s] + nums[e]
                delta = abs(x - target)
        return x





nums = [-1, 2, 1, -4]
print Solution().threeSumClosest(nums, 1)