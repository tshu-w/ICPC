#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import *

num = 600851475143
ans = 0
sqrtn = int(sqrt(num))
prime = [True] * sqrtn

for i in range(2, sqrtn):
    if prime[i]:
        for j in range(2, sqrtn // i):
            prime[i * j] = False
        if num % i == 0:
            ans = max(ans, i)
            while (num % i == 0):
                num /= i
print(max(ans, num))
