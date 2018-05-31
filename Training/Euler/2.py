#!/usr/bin/env python
# -*- coding: utf-8 -*-

sum = 0
a, b = 1, 2
while a <= 4000000:
    if a % 2 == 0:
        sum += a
    a, b = b, a + b
print(sum)
