#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import *

n = 10001  # Pn < nlnn + nlnlnn (n >= 6)
N = int(n * log(n) + n * log(log(n)))
isPrime = [True] * N
cnt = 0

for i in range(2, N):
    if isPrime[i]:
        for j in range(2 * i, N, i):
            isPrime[j] = False
        cnt += 1
        if cnt == n:
            print(i)
