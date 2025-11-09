#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        area = 0

        for i in range(len(height)):
            if (len(stack) != 0 and height[stack[-1]] <= height[i]):
                res = 0
                while (len(stack) != 0 and height[stack[-1]] <= height[i]):
                    j = stack.pop()
                    if (len(stack) == 0):
                        area += height[j] * (i - j - 1) - res
                    else:
                        res += height[j] * (j - stack[-1])

                if (len(stack) != 0):
                    area += height[i] * (i - stack[-1] - 1) - res

            stack.append(i)

        return area
