from collections import defaultdict
class Solution:
    def find(self, x):
        while x != self.maps[x]:
            x = self.maps[x]
        return x
    def longestConsecutive(self, nums):
        self.maps = dict()
        for x in nums:
            self.maps[x] = x 
        for x in nums:
            if x-1 in self.maps:
                self.maps[self.find(x-1)] = self.find(x)
            if x+1 in self.maps:
                self.maps[self.find(x+1)] = self.find(x)
        rtmap = defaultdict(int)
        for x in nums:
            rtmap[self.find(x)] += 1
        return max(list(rtmap.values()))

        # minval = min(nums)
        # maxval = max(nums)
        # delt = maxval - minval + 1
        # uf = [maxval+1 for _ in range(delt)]
        # offset = minval
        # for x in nums:
        #     uf[x-offset] = x
        # for x in nums:
        #     if x - 1 >= minval and uf[x-1-offset] != maxval+1:
        #         rt_x_1 = self.find(x-1, uf,offset)
        #         rt_x = self.find(x, uf,offset)
        #         uf[rt_x - offset] = rt_x_1
        #     if x + 1 <= maxval and uf[x+1-offset] != maxval+1:
        #         rt_x_1 = self.find(x+1, uf,offset)
        #         rt_x = self.find(x, uf,offset)
        #         uf[rt_x - offset] = rt_x_1
        # rtmap = defaultdict(int)
        # for x in range(minval, maxval+1):
        #     if uf[x-offset] != maxval + 1:
        #         print(x)
        #         rtmap[self.find(x, uf,offset)]+=1
        # return max(list(rtmap.values()))

s1 = Solution()
nums = [0,1,2,4,8,5,6,7,9,3,55,88,77,99,999999999]
res = s1.longestConsecutive(nums)
print(res)