#!/usr/bin/env python
# -*- coding: utf-8 -*-

def isPalindrome(n):
    return str(n) == str(n)[::-1]

ans = 0
for i in range(100, 1000):
    for j in range(i, 1000):
        if (isPalindrome(i * j)):
            ans = max(ans, i * j)
print(ans)
